cmake_minimum_required(VERSION 3.26)
project(assignment_script)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment_script
        main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static")