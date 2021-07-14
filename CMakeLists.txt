cmake_minimum_required(VERSION 3.1)

project(CppXplore)

set(CMAKE_CXX_STANDARD 11)

find_package (Threads REQUIRED)

add_executable(demo_vec src/demo_vec.cpp)
add_executable(demo_cpmv src/demo_cpmv.cpp)
add_executable(demo_rvalue src/demo_rvalue.cpp)
add_executable(demo_find_closest src/demo_find_closest.cpp)

add_executable(demo_condvar src/demo_condvar.cpp)
target_link_libraries(demo_condvar ${CMAKE_THREAD_LIBS_INIT})
