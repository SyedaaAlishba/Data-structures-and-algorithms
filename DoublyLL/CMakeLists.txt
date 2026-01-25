cmake_minimum_required(VERSION 4.1)
project(DoublyLL CUDA)

set(CMAKE_CUDA_STANDARD 20)

add_executable(DoublyLL main.cpp
        main.cpp)

set_target_properties(DoublyLL PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)
