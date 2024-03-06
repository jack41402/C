cmake_minimum_required(VERSION 3.23)
project(TEST C)

set(CMAKE_C_STANDARD 11)

add_executable(TEST main.c)

add_executable(house house.c)
