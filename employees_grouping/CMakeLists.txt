cmake_minimum_required(VERSION 3.14)

project(empoyees_grouping)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/)

set(SOURCES
    src/main.cpp
    src/employee.cpp
)

set(HEADERS
    include/employee.h
    include/department.h
)

add_executable(employee_grouping ${SOURCES} ${HEADERS})