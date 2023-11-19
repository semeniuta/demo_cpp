cmake_minimum_required(VERSION 3.5)

project(demo_cpp)

set(CMAKE_CXX_STANDARD 20)

find_package(fmt)

find_package(Boost 1.8 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
include_directories((${EINGEN3_INCLUDE_DIR}))
# https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux
find_package(Threads REQUIRED)

add_executable(demo_vec src/demo_vec.cpp)
add_executable(demo_cpmv src/demo_cpmv.cpp)
add_executable(demo_rvalue src/demo_rvalue.cpp)
add_executable(demo_find_closest src/demo_find_closest.cpp)
add_executable(demo_map src/demo_map.cpp)
add_executable(demo_read_stl src/demo_read_stl.cpp)

add_executable(demo_ranges src/demo_ranges.cpp)
target_link_libraries(demo_ranges fmt::fmt)

add_executable(demo_condvar src/demo_condvar.cpp)
target_link_libraries(demo_condvar ${CMAKE_THREAD_LIBS_INIT})
