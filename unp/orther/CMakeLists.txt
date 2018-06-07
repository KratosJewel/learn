cmake_minimum_required(VERSION 3.8)
project(learn)

set(CMAKE_CXX_STANDARD 17)


set(CLIENT_FILES client.cpp ../helper.h)
set(SERVER_FILES server.cpp ../helper.h)

add_executable(client ${CLIENT_FILES})
add_executable(server ${SERVER_FILES})
