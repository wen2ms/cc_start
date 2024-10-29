cmake_minimum_required(VERSION 3.10)

project(staff_management_system)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/)

set(SOURECES src/main.cpp src/staff_list.cpp src/staff_management_system.cpp src/staff.cpp)

add_executable(staff_management_system ${SOURCES})
