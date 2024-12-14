cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(demo)

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
 
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS})