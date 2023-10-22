cmake_minimum_required(VERSION 3.20)

# Set the name of the project and the language it is written in
# CXX is included because we are using googletest.
project(C_Callback C CXX)

# create a shared library
add_library(C_Callback SHARED)

# add the include directory to the library
target_include_directories(C_Callback PUBLIC include)

# add the sources to the library
target_sources(C_Callback PRIVATE src/C_Callback.c)

# Add the tests
include(CTest)
add_subdirectory(tests)

