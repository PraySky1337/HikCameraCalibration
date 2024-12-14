#include "camera.h"
std::string path = "../picture/";
int main(){
    MyCamera::captureSave(path);
    MyCamera camera(path);
    std::cout << "----------------" << "方形标定板标定结果" << "----------------" << std::endl;
    std::cout << "相机畸变矩阵: " << camera.get_Distcoeffs_Mat() << std::endl;
    std::cout << "相机内参矩阵：" <<  camera.get_Camera_Mat() << std::endl;
    std::cout << "相机标定误差：" << camera.get_rms() << "像素" << std::endl;
    std::cout << "----------------" << "方形标定板标定结果" << "----------------" << std::endl;
    return 0;
}