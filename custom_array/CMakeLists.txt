cmake_minimum_required(VERSION 3.14)

project(custom_array)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/)

set(SOURCE src/main.cpp)

add_executable(custom_array ${SOURCE})

