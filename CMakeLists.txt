cmake_minimum_required(VERSION 2.8)
project( my_hw )
find_package( OpenCV REQUIRED )
add_executable( my_hw my_hw.cpp )
target_link_libraries( my_hw ${OpenCV_LIBS} )


