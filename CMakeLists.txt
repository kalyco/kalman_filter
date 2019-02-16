cmake_minimum_required(VERSION 2.8.4)
project(kalman)

find_package( OpenCV REQUIRED )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EIGEN_INC_DIR /usr/local/Cellar/eigen/)
set(OpenCV_INCLUDE_DIRS /usr/local/Cellar/opencv/)

include_directories(${OpenCV_INCLUDE_DIRS} ${EIGEN_INC_DIR})

set(SOURCE_FILES KalmanFilter.cpp sail_prediction.cpp)
add_executable(kalman ${SOURCE_FILES})