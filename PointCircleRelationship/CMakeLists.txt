cmake_minimum_required(VERSION 3.10)

project(PointCircleRelationship)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    main.cpp
    src/Point.cpp
    src/Circle.cpp
    src/Utilities.cpp
)

add_executable(point_circle ${SOURCES})
