project (CppCode)
cmake_minimum_required(VERSION 2.8)

# Set the directory name where executables go
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY build)

# Various programs
add_executable(hello src/hello.cpp)
add_executable(mem_fun src/mem_fun.cpp)

# These can be set via env variables to the location of
# the boost library
# set (CMAKE_INCLUDE_PATH /opt/personal/pkg/boost/include)
# set (CMAKE_LIBRARY_PATH /opt/personal/pkg/boost/lib)

find_package( Boost 1.46.1 REQUIRED COMPONENTS program_options )

if(Boost_FOUND)
    # Build statically so I don't have to set DYLD_LIBRARY_PATH
    set (Boost_USE_STATIC_LIBS ON)

    # Setup the include dir for boost
    include_directories(${Boost_INCLUDE_DIRS})

    add_executable(boost_hello src/boost_hello.cpp)
    target_link_libraries(boost_hello ${Boost_LIBRARIES})

    add_executable(scoped_ptr src/scoped_ptr.cpp)
endif()

# vim: sts=4 sw=4 ts=4 et ft=cmake
