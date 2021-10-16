cmake_minimum_required(VERSION 3.10)
project(cplusplus_primer)

set(SOURCE
    18/animal.cpp
)

add_executable(cplusplus_primer ${SOURCE})

target_include_directories(cplusplus_primer
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/18
)
