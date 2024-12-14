find_package(Threads)
find_package(fmt REQUIRED)
find_package(glog REQUIRED)
find_package(OpenCV REQUIRED)

add_library(hik_driver STATIC include/HikDriver/HikDriver.h src/HikDriver.cpp)
set_target_properties(hik_driver PROPERTIES
        LINKER_LANGUAGE CXX
        )

target_include_directories(hik_driver PUBLIC include)
target_include_directories(hik_driver PUBLIC /opt/MVS/include)

target_link_libraries(hik_driver PUBLIC
    Threads::Threads
    glog::glog
    fmt::fmt
    ${OpenCV_LIBS}
    X11
    MvCameraControl)
