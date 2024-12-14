#include <filesystem>
#include <random>
#include <sstream>
#include <iomanip>
#include "camera.h" 
#include "HikDriver/HikDriver.h"
using namespace std;
using namespace cv;
/// @brief 
/// @param board_file_path 
/// @param square_size 
/// @param board_size 
/// @param extension 
MyCamera::MyCamera(string& board_file_path, const Size& square_size,const Size& board_size, const string& extension){
    // 初始化常量
    m_board_size = board_size;
    m_square_size = square_size;
    m_camera_mat = Mat(3, 3, CV_32FC1, Scalar::all(0));
    m_distcoeffs_mat = Mat(1, 5, CV_32FC1, Scalar::all(0));
    // 处理图像 计算相机内
    this->loadPic(board_file_path, extension);
    this->findCornerPoint();
    this->convertPoint2Dto3D(square_size);
    this->standardization();
} 
int MyCamera::loadPic(const string board_file_path, string extension){
    namespace fs = std::filesystem;
    extension = "." + extension;
    vector<fs::path> imgFiles;
    try{
    for(const auto &it : fs::directory_iterator(board_file_path)){
        if(it.is_regular_file() && it.path().extension() == extension){
            imgFiles.push_back(it.path());
        }
    }
    for(int i = 0 ; i < imgFiles.size(); i++){
        Mat temp_img = imread(imgFiles[i]);
        m_img.push_back(temp_img);
    } if(m_img.empty()){
        cerr << "文件夹中并没有" << extension << "文件！" << endl;return -1;
    }
} catch(const fs::filesystem_error& e) {
    cerr << "文件系统错误！" << e.what() <<endl;
} catch(const exception& e) {
    cerr << "错误：" << e.what() << endl;
}
    return 0;
}
void MyCamera::findCornerPoint() {
    for(int i = 0 ; i < m_img.size() ; i++){
        Mat gray;
        vector<Point2f> temp_corner;
        cvtColor(m_img[i], gray, COLOR_BGR2GRAY);
        imshow("gray", gray);
        bool found = findChessboardCorners(gray, m_board_size, temp_corner);
        if (!found) {
            std::cerr << "未找到棋盘点！" << std::endl; 
        }
        else{
        m_corner_points2d.push_back(temp_corner);
        // -------debug--------
        find4QuadCornerSubpix(gray, temp_corner, Size(5, 5));
        auto temp_img = m_img[i];
        drawChessboardCorners(temp_img,m_board_size,temp_corner,true);
        imshow("方形标定板检测结果", temp_img);
        waitKey(30);
        // -------debug--------
        }
    }
} 

void MyCamera::convertPoint2Dto3D(const Size& square_size){
    //遍历整个图像
    for(int i = 0 ; i < m_corner_points2d.size() ; i++){
        vector<Point3f> tempPointSet;
        for(int j = 0 ; j < m_board_size.height ; j++){
            for(int k = 0 ; k < m_board_size.width ; k++){
                Point3f real_point;
                real_point.x = j * square_size.width;
                real_point.y = k * square_size.height;
                real_point.z = 0;
                tempPointSet.push_back(real_point);
            }
        }
        m_corner_points3d.push_back(tempPointSet);
    }
}

void MyCamera::standardization(){
    Size img_size;
    // assert(!m_img.empty());
    img_size.width = m_img[0].cols;
    img_size.height = m_img[0].rows;
    this->m_rms = calibrateCamera(m_corner_points3d, m_corner_points2d, img_size, m_camera_mat, m_distcoeffs_mat, m_rvecs, m_tvecs, 0);
}

void MyCamera::captureSave(const string& path ,const string& extension){
    HikDriver hik_driver;
    if (hik_driver.isConnected()) {
        hik_driver.setExposureTime(20000);
        hik_driver.setGain(15);
        hik_driver.showParamInfo();
        hik_driver.startReadThread();
    } else {
        return;
    }
    HikFrame frame;
    cv::Mat img;
    vector<Mat> need_save_picture;
    while(true) {
        frame = hik_driver.getFrame(); 
        img = frame.getRgbFrame()->clone();
        if (img.empty()) {
            cout << "img is empty" << endl;
            continue;
        }
        // 克隆一个副本用于存储
        Mat original_img = img.clone();
        Point lower_left_point(0, img.rows -1);
        Point top_left_point(0 + 10,0 + 30);
        int font_face = 0;
        double fontscale = 1;
        Scalar color = Scalar(0, 255, 0);
        putText(img, "PressEsctoQuit", lower_left_point, font_face, fontscale, color);
        putText(img, "PressStoCapturing", top_left_point, font_face, fontscale, color);
        imshow("Camera", img);
        //监听按键
        int monitor = -1;
            if((monitor = waitKey(30)) != -1) {
            if(monitor == 27)break;
            if(monitor == 'S')need_save_picture.push_back(original_img);
        }
    }
    hik_driver.stopReadThread();
    //这个算法有待优化 ----TODO----
    if(!need_save_picture.empty()){
        auto random = [](const string& path, const string& extension){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<uint64_t> dis(0,numeric_limits<uint64_t>::max());
        uint64_t random_number = dis(gen);
        stringstream ss;
        ss << "img_" << hex << setw(16) << setfill('0') << random_number;
        string the_path = path + ss.str() + "." + extension;
        return the_path;
        };
        //存储每张图片
        for(int i = 0 ; i < need_save_picture.size() ; i++){
            string path_name_extension = random(path,extension);
            imwrite(path_name_extension, need_save_picture[i]);
        }
    }
}