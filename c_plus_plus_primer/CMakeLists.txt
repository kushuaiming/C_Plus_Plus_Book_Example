cmake_minimum_required(VERSION 3.10)
project(c_plus_plus_primer)

set(SOURCE
    18/animal.cpp
)

add_executable(c_plus_plus_primer ${SOURCE})

target_include_directories(c_plus_plus_primer
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/18
)
