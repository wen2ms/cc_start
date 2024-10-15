cmake_minimum_required(VERSION 3.14)

project(calculator_cc_start)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/calculator.cpp
    src/scientific_calculator.cpp
    src/calculator_app.cpp
)

set(HEADERS
    include/calculator.h
    include/scientific_calculator.h
    include/calculator_app.h
)

add_executable(calculator_cc_start ${SOURCES} ${HEADERS})

target_link_libraries(calculator_cc_start Qt6::Widgets)