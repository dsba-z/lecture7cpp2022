cmake_minimum_required(VERSION 3.0)

project(Lectures_6_7_Demos CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

#### the list of targets ####
add_executable(ex1_refs ex1_refs/main.cpp)
add_executable(ex2_range_for ex2_range_for/main.cpp)
add_executable(ex3_vectors ex3_vectors/main.cpp common/vect_utils.h common/vect_utils.cpp)
add_executable(ex4_cinema ex4_cinema/main.cpp)

