cmake_minimum_required(VERSION 3.24)
project(cplusplus_learning)

set(CMAKE_CXX_STANDARD 17)

add_library(
        CNFCalculator
        CNFCalculator.cpp
        CNFCalculator.h
)

add_executable(
        cplusplus_learning
        main.cpp
        #        codeforce.cpp
)

target_link_libraries(
        cplusplus_learning
        CNFCalculator
)
