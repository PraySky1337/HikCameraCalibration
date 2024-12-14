cmake_minimum_required(VERSION 3.5)

# 项目信息
project(QtParameterAdjustment VERSION 1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 查找 Qt5 包
find_package(Qt5Widgets REQUIRED)

# 启用 Qt 自动处理 MOC、UI 文件
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 设置源文件列表
file(GLOB_RECURSE SOURCES)
# 添加可执行文件
add_executable(QtParameterAdjustment ${SOURCES})

# 链接 Qt5 Widgets 库
target_link_libraries(QtParameterAdjustment Qt5::Widgets)

# 设置 C++ 标准
set_target_properties(QtParameterAdjustment PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

# 可选：设置生成的可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# 查找 Qt5 包
find_package(Qt5Core REQUIRED)

# 添加 QtCore 库到目标链接
target_link_libraries(QtParameterAdjustment Qt5::Core)
