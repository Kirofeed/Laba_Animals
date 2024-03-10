cmake_minimum_required(VERSION 3.27)
project(Laba_Animals)

set(CMAKE_CXX_STANDARD 23)

add_executable(Laba_Animals main.cpp
        cat.h
        dog.cpp
        cat.cpp
        parrot.h
        parrot.cpp
        fish.h
        fish.cpp)
add_executable(test test.cpp)
