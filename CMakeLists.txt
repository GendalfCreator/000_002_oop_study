cmake_minimum_required(VERSION 3.5)

project(000_002_oop_study LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    000_002_oop_study main.cpp
    node.h node.cpp
    stack.h stack.cpp
    )

