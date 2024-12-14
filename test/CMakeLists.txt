cmake_minimum_required(VERSION 3.10)
project(demo)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
# 设置编译器标准
set(CMAKE_CXX_STANDARD 11)
file(GLOB_RECURSE SRC1 src/*.cpp)
file(GLOB_RECURSE SRC2 opt/MVS/lib/*.so)
list(APPEND SRC1 "main.cpp")
add_executable(${PROJECT_NAME} ${SRC1} ; ${SRC2})
# 添加外部库头文件路径
target_include_directories(${PROJECT_NAME} PRIVATE /opt/MVS/include)
target_include_directories(${PROJECT_NAME} PUBLIC include)
# 添加外部库链接路径
target_link_libraries(${PROJECT_NAME} ${SRC2})