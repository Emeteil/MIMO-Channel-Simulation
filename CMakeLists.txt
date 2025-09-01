cmake_minimum_required(VERSION 3.20)

project(MIMO VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}) # without ../header.h
include_directories("utils")

file(GLOB SOURCE_LIB "utils/*.cpp")

add_library(MY_LIB ${SOURCE_LIB})

add_executable(a.out main.cpp)

target_link_libraries(a.out MY_LIB)