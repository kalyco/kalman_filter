cmake_minimum_required(VERSION 2.8.4)
project(kalman)

find_package( OpenCV REQUIRED )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EIGEN_INC_DIR /usr/local/Cellar/eigen/)
# set(OpenCV_INCLUDE_DIRS /usr/local/Cellar/opencv/)
set(OpenCV_DIR /usr/local/Cellar/opencv/4.0.1/share/OpenCV)

include_directories(
	${OpenCV_DIR}
	${EIGEN_INC_DIR}
	${CMAKE_SOURCE_DIR}/include
	/usr/local/Cellar/opencv/4.0.1/)

find_package(OpenCV REQUIRED)
set(SOURCE_FILES KalmanFilter.cpp sail_prediction.cpp)
add_executable(kalman ${SOURCE_FILES})