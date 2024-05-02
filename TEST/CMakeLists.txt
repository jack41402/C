cmake_minimum_required(VERSION 3.23)
project(TEST C)

set(CMAKE_C_STANDARD 11)

add_executable(TEST main.c
        quiz1.c)
add_executable(quiz1 quiz1.c)