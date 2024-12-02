cmake_minimum_required(VERSION 3.14)

project(algorithm_find)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(algorithm_find_config.h.in algorithm_find_config.h)

add_executable(algorithm_find algorithm_find.cpp)

target_include_directories(algorithm_find PUBLIC ${PROJECT_BINARY_DIR})