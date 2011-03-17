project (CppCode)
cmake_minimum_required(VERSION 2.8)

# Set the directory name where executables go
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY build)
set (CMAKE_INCLUDE_PATH /opt/personal/pkg/boost/include)
set (CMAKE_LIBRARY_PATH /opt/personal/pkg/boost/lib)
set (Boost_USE_STATIC_LIBS ON)

find_package( Boost 1.46.1 COMPONENTS program_options )

# Various programs
add_executable(hello src/hello.cpp)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(boost_hello src/boost_hello.cpp)
    target_link_libraries(boost_hello ${Boost_LIBRARIES})
endif()

# vim: sts=4 sw=4 ts=4 et ft=cmake
