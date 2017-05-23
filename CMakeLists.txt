cmake_minimum_required(VERSION 3.6)
project(ImageProcess)

set(OpenCV_DIR "/usr/local/opt/opencv3/share/OpenCV")
# OpenCV
FIND_PACKAGE( OpenCV REQUIRED )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
FIND_PACKAGE(Boost REQUIRED program_options)
set(SOURCE_FILES main.cpp GradientShow.cpp GradientShow.h DrawUtils.h DrawUtils.cpp BandFilter.cpp BandFilter.h)
add_executable(GradientShow ${SOURCE_FILES})
add_executable(SnapImage SnapImage.cpp)
target_link_libraries(GradientShow ${OpenCV_LIBS} ${Boost_PROGRAM_OPTIONS_LIBRARY})
target_link_libraries(SnapImage ${OpenCV_LIBS} ${Boost_PROGRAM_OPTIONS_LIBRARY})