cmake_minimum_required(VERSION 3.14)

project(algorithm_replace)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(algorithm_replace_config.h.in algorithm_replace_config.h)

add_subdirectory(tvshow)

add_executable(algorithm_replace algorithm_replace.cpp)

target_link_libraries(algorithm_replace PUBLIC tvshow)

target_include_directories(algorithm_replace PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/tvshow")