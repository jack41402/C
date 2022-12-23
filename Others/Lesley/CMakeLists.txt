cmake_minimum_required(VERSION 3.24)
project(Lesley C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lesley
        assgn6_D1166510.c
        queue_dynamic_array.h
        queue_dynamic_array_main.c)
