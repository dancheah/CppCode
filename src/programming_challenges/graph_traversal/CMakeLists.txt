project (GraphTraversal)
cmake_minimum_required(VERSION 2.8)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY build)
set (CMAKE_CXX_FLAGS "-g") 
set (CMAKE_CXX_FLAGS_DEBUG "-g") 

add_executable(bicoloring bicoloring.cpp)

# vim: sts=4 sw=4 ts=4 et ft=cmake
