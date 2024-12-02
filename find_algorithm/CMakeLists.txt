cmake_minimum_required(VERSION 3.14)

project(find_algorithm)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(find_algorithm_config.h.in find_algorithm_config.h)

add_executable(find_algorithm find_algorithm.cpp)

target_include_directories(find_algorithm PUBLIC ${PROJECT_BINARY_DIR})