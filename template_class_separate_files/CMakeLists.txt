cmake_minimum_required(VERSION 3.10)

project(template_class_separate_files)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/)

set(SOURCE src/main.cpp)

add_executable(template_class_separate_files ${SOURCE})