cmake_minimum_required(VERSION 3.10)
project(inside_the_c_plus_plus_object_model)

set(SOURCE
    chapter_3_the_semantics_of_data/sizeof_virtual_base_class.cc
)

add_executable(inside_the_c_plus_plus_object_model ${SOURCE})
