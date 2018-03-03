cmake_minimum_required(VERSION 3.8)
project(learn)

set(CMAKE_CXX_STANDARD 17)


set(CLIENT_FILES chapter1.2.cpp helper.h)
set(SERVER_FILES chapter1.5.cpp helper.h)
add_executable(learn ${CLIENT_FILES})
add_executable(serve ${SERVER_FILES})
