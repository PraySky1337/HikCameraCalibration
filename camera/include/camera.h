#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>

class MyCamera{
public:
    MyCamera() = delete;
    MyCamera(int real_size_x , int real_size_y);
    ~MyCamera(){};
    cv::Mat get_Camera_Mat(){return m_camera_mat;}
    cv::Mat get_Distcoeffs_Mat(){return m_distcoeffs_mat;}
private: 
    int ReadPic();
    void Standardization();
    void findCornerPoint();
    void ConvertPoint2Dto3D(int real_size_x , int real_size_y);

    cv::Mat m_img_chess_board;
    std::vector<cv::Mat> m_rvecs; // 相机坐标系与世界坐标系之间的旋转向量
    std::vector<cv::Mat> m_tvecs; // 相机坐标系与世界坐标系之间的平移向量
    std::vector<std::vector<cv::Point2f>> m_corner_points2d; // 标定板内角坐标(二维像素坐标)
    std::vector<std::vector<cv::Point3f>> m_corner_points3d; // 标定板内角坐标（三维坐标）
    cv::Size m_board_size;
    cv::Mat m_camera_mat; // 相机内参矩阵
    cv::Mat m_distcoeffs_mat; // 相机的畸变系数矩阵
};