cmake_minimum_required(VERSION 3.9)
project(Kursach)

set(CMAKE_CXX_STANDARD 17)

file(GLOB src
        "*.h"
        "*.cpp"
        )

add_executable(Kursach main.cpp)