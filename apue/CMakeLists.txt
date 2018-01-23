cmake_minimum_required(VERSION 3.8)
project(learn)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES chapter8.6.cpp)
add_executable(learn ${SOURCE_FILES})

#查找库并链接
find_library(libboost_timer_path boost_timer ${link_dir})
target_link_libraries(learn ${libboost_timer_path})