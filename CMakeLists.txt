cmake_minimum_required(VERSION 3.1)

project(CppXplore)

set(CMAKE_CXX_STANDARD 17)

# https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux
find_package(Threads REQUIRED)

add_executable(demo_vec src/demo_vec.cpp)
add_executable(demo_cpmv src/demo_cpmv.cpp)
add_executable(demo_rvalue src/demo_rvalue.cpp)
add_executable(demo_find_closest src/demo_find_closest.cpp)
add_executable(demo_map src/demo_map.cpp)
add_executable(demo_read_stl src/demo_read_stl.cpp)
add_executable(demo_ranges src/demo_ranges.cpp)

add_executable(demo_condvar src/demo_condvar.cpp)
target_link_libraries(demo_condvar ${CMAKE_THREAD_LIBS_INIT})
