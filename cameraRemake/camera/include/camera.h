#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

class MyCamera{
public:
    MyCamera(std::string& board_file_path, const cv::Size& square_size = cv::Size(20,20),const cv::Size& board_size = cv::Size(9,6), const std::string& extension = "png");
    ~MyCamera() = default;
    inline cv::Mat get_Camera_Mat() { return m_camera_mat; }
    inline cv::Mat get_Distcoeffs_Mat() { return m_distcoeffs_mat; }
    inline double get_rms() { return m_rms; }
public:
    static void captureSave(const std::string& path, const std::string& extension = "png");
private: 
    /// @brief 
    /// @param board_file_string 
    /// @param extension 
    /// @return 
    int loadPic(const std::string board_file_string,std::string extension); //读取这一组图片

    void standardization(); // 获取这个相机的内参矩阵和畸变矩阵
    void findCornerPoint(); // 找到这个函数的二维内角坐标

    /// @brief 将findCornerPoint方法获得的m_point_2d转化成m_point_3d
    /// @param square_size 
    void convertPoint2Dto3D(const cv::Size& square_size); // 将二维内角坐标转化为三维坐标
private:
    std::vector<cv::Mat> m_img;
    std::vector<cv::Mat> m_rvecs; // 相机坐标系与世界坐标系之间的旋转向量
    std::vector<cv::Mat> m_tvecs; // 相机坐标系与世界坐标系之间的平移向量
    std::vector<std::vector<cv::Point2f>> m_corner_points2d; // 标定板内角坐标(二维像素坐标)
    std::vector<std::vector<cv::Point3f>> m_corner_points3d; // 标定板内角坐标（三维坐标）
    cv::Size m_board_size; // 这个标定板有x行，y列
    cv::Size m_square_size; // 棋盘格每个格子的真实尺寸
    cv::Mat m_camera_mat; // 相机内参矩阵
    cv::Mat m_distcoeffs_mat; // 相机的畸变系数矩阵
    double m_rms; // 误差 (单位 : 像素点)
};