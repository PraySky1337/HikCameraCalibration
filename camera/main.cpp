#include "camera.h"

int main(){
    MyCamera camera(10,10);
    std::cout << "---------------------------------标定结果---------------------------------"<<std::endl;
    std::cout<<camera.get_Camera_Mat()<<std::endl;
    std::cout<<camera.get_Distcoeffs_Mat()<<std::endl;
    std::cout << "---------------------------------标定结果---------------------------------"<<std::endl;
    return 0;
}