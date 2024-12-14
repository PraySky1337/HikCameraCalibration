// #include "opencv2/highgui.hpp"
// #include "opencv2/imgproc.hpp"
// #include <iostream>
// using namespace cv;
// using namespace std;
// static void help()
// {
//     cout << "This program demonstrates finding the minimum enclosing box, triangle or circle of a set\n"
//          << "of points using functions: minAreaRect() minEnclosingTriangle() minEnclosingCircle().\n"
//          << "Random points are generated and then enclosed.\n\n"
//          << "Press ESC, 'q' or 'Q' to exit and any other key to regenerate the set of points.\n\n";
// }
// int main( int /*argc*/, char** /*argv*/ )
// {
//     help();
//     Mat img(500, 500, CV_8UC3, Scalar::all(0));
//     RNG& rng = theRNG();
//     for(;;)
//     {
//         int i, count = rng.uniform(1, 101);
//         vector<Point> points;
//         // Generate a random set of points
//         for( i = 0; i < count; i++ )
//         {
//             Point pt;
//             pt.x = rng.uniform(img.cols/4, img.cols*3/4);
//             pt.y = rng.uniform(img.rows/4, img.rows*3/4);
//             points.push_back(pt);
//         }
//         // Find the minimum area enclosing bounding box
//         Point2f vtx[4];
//         RotatedRect box = minAreaRect(points);
//         box.points(vtx);
//         box.points(vtx);
//         // Find the minimum area enclosing circle
//         Point2f center;
//         float radius = 0;
//         minEnclosingCircle(points, center, radius);
//         img = Scalar::all(0);
//         // Draw the points
//         for( i = 0; i < count; i++ )
//             circle( img, points[i], 3, Scalar(0, 0, 255), FILLED, LINE_AA );
//         // Draw the bounding box
//         std::string number[4] = {"0", "1", "2", "3"};
//         for( i = 0; i < 4; i++ ){
//             line(img, vtx[i], vtx[(i+1)%4], Scalar(0, 255, 0), 1, LINE_AA);
//             putText(img, number[i], vtx[i], 1, 5, cv::Scalar(0,255,0));
//         }
//         std::cout << "angle" << box.angle; 
//         std::cout << " width" << box.size.width << " height:" << box.size.height << std::endl; 
//         imshow( "Rectangle, triangle & circle", img );
//         char key = (char)waitKey();
//         if( key == 27 || key == 'q' || key == 'Q' ) // 'ESC'
//             break;
//     }
//     return 0;
// }

// #include <opencv2/highgui.hpp>
// #include <opencv2/imgproc.hpp>
// #include <iostream>
// #include <cmath>

// using namespace cv;
// using namespace std;

// // 全局变量
// int angle = 0; // 旋转角度，初始为 0
// RotatedRect rotatedRect(Point2f(250, 250), Size2f(200, 100), 0); // 初始旋转矩形
// Mat img(500, 500, CV_8UC3, Scalar::all(0));

// // 回调函数，用于更新旋转矩形的角度
// void onAngleChange(int, void*) {
//     // 更新旋转矩形的角度
//     rotatedRect.angle = angle;

//     // 清空图像并绘制新的旋转矩形
//     img = Scalar::all(0);

//     // 获取矩形的 4 个顶点
//     Point2f vertices[4];
//     rotatedRect.points(vertices);

//     // 绘制矩形边框
//     for (int i = 0; i < 4; i++) {
//         line(img, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 2, LINE_AA);
//     }

//     // 绘制矩形中心
//     circle(img, rotatedRect.center, 5, Scalar(0, 0, 255), FILLED, LINE_AA);

//     // 在图像上显示角度
//     string angleText = "Angle: " + to_string(angle) + " deg";
//     putText(img, angleText, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 255), 2, LINE_AA);

//     // 打印相关变量
//     cout << "Angle: " << angle << " deg" << endl;
//     cout << "Vertices:" << endl;
//     for (int i = 0; i < 4; i++) {
//         cout << "P" << i << ": (" << vertices[i].x << ", " << vertices[i].y << ")" << endl;
//     }
//     cout << endl;

//     // 显示图像
//     imshow("Rotated Rect", img);
// }

// int main() {
//     // 创建窗口
//     namedWindow("Rotated Rect", WINDOW_AUTOSIZE);

//     // 创建轨迹条用于调整角度
//     createTrackbar("Angle", "Rotated Rect", &angle, 360, onAngleChange);

//     // 初始化角度
//     onAngleChange(0, nullptr);

//     // 等待用户退出
//     waitKey(0);
//     return 0;
// }
#include <iostream>
int* ptr = nullptr;
void pointer(int* const ptr_) noexcept{
    ptr = ptr_;
}
int main() {
    {
    int a = 1;
    pointer(&a);
    std::cout << *ptr;
    }
    std::cout << *ptr;
    std::cout << *ptr;
}







