cmake_minimum_required(VERSION 3.17)

set(CXX_STANDARD_REQUIRED 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(camera)

if(NOT CMAKE_BUILD_TYPE)
 set(CMAKE_BUILD_TYPE Release)
endif()
message("--CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

find_package(OpenCV REQUIRED)
file(GLOB_RECURSE SRC src/*.cpp)
list(APPEND SRC "main.cpp")

add_executable(${PROJECT_NAME} ${SRC})

# 链接头文件目录 
target_include_directories(${PROJECT_NAME} PUBLIC include) 
# 链接OpenCV库
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})