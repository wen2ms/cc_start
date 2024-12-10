cmake_minimum_required(VERSION 3.14)

project(competition_process_system VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(cps_config.h.in cps_config.h)

add_executable(competition_process_system src/main.cpp src/competition_process_system.cpp src/player.cpp)

target_include_directories(competition_process_system PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/include")