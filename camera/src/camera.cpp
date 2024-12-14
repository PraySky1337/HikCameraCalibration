#include "camera.h"

MyCamera::MyCamera(int real_size_x , int real_size_y){
    using namespace std;
    using namespace cv;
    m_board_size = cv::Size(9,6);
    m_camera_mat = Mat(3,3,CV_32FC1, Scalar::all(0));
    m_distcoeffs_mat = Mat(1, 5, CV_32FC1, Scalar::all(0));
    this->ReadPic();
    this->findCornerPoint();
    this->ConvertPoint2Dto3D(real_size_x, real_size_y);
    this->Standardization();
}
void MyCamera::findCornerPoint(){
    using namespace std;
    using namespace cv;;
    Mat gray;
    vector<Point2f> temp_corner;
    cvtColor(m_img_chess_board,gray,COLOR_BGR2GRAY);
    imshow("gray", gray);
    waitKey(0);
    bool found = findChessboardCorners(gray,m_board_size,temp_corner);      // 寻找方形标定板角点
    if(found){
    m_corner_points2d.push_back(temp_corner);
    find4QuadCornerSubpix(gray,temp_corner,Size(5,5));                      // 细化角点
    drawChessboardCorners(m_img_chess_board,m_board_size,temp_corner,true); // 绘制角点
    imshow("方形标定板检测结果",m_img_chess_board);
    waitKey(0);
    }else{
        cerr << "未找到棋盘角点！" << endl;
    }
    return ;
}
int MyCamera::ReadPic(){
    using namespace std;
    using namespace cv;
    m_img_chess_board = imread("img_chess_board.png");
    if(m_img_chess_board.data){return 0}
    else{cerr << "没有正确读取到图像"}
    // VideoCapture cap(0);
    // cap >> m_img_chess_board;
    // cap.release();
    // imwrite("img_chess_board.png",m_img_chess_board);
}
void MyCamera::ConvertPoint2Dto3D(int real_size_x , int real_size_y){
    using namespace std;
    using namespace cv;
    Size square_size = Size(real_size_x,real_size_y); // 棋盘格每个格子的真实尺寸
    for(int i = 0 ; i < m_corner_points2d.size() ; i++){
        vector<Point3f> tempPointSet;
        for(int j = 0 ; j < m_board_size.height ; j++){
            for(int k = 0 ; k < m_board_size.width ; k++){
                Point3f realPoint;
                realPoint.x = j*square_size.width;
                realPoint.y = j*square_size.height;
                realPoint.z = 0;
                tempPointSet.push_back(realPoint);
            }
        }
        m_corner_points3d.push_back(tempPointSet);
    }
}
void MyCamera::Standardization(){
    using namespace std;
    using namespace cv;
    Size img_size;
    img_size.width = m_img_chess_board.cols;
    img_size.height = m_img_chess_board.rows;
    // 相机的五个畸变系数 k1,k2,p1,p2,k3
    calibrateCamera(m_corner_points3d, m_corner_points2d, img_size, m_camera_mat, m_distcoeffs_mat, m_rvecs, m_tvecs, 0);
}