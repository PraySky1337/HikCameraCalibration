cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

project(camera)

message("${PROJECT_NAME} is building")

find_package(OpenCV REQUIRED)

file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

file(GLOB_RECURSE INC ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(camera ${SRC} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    ${OpenCV_INCLUDE_DIRS}) 
target_link_libraries(${PROJECT_NAME} PUBLIC
    ${OpenCV_LIBS}
    hik_driver)