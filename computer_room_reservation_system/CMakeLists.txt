cmake_minimum_required(VERSION 3.14)

project(computer_room_reservation_system)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

aux_source_directory("${PROJECT_SOURCE_DIR}/src" SOURCE)

add_executable(computer_room_reservation_system "${SOURCE}")

target_include_directories(computer_room_reservation_system PUBLIC "${PROJECT_SOURCE_DIR}/include")