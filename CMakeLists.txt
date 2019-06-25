cmake_minimum_required(VERSION 3.1)

project(CppXplore)

set(CMAKE_CXX_STANDARD 11)

#set(core_sources src/...)

add_executable(demo_vec src/demo_vec.cpp)
add_executable(demo_cpmv src/demo_cpmv.cpp)