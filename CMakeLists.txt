# FILEPATH: /C:/Users/green/source/repos/callbackDemo/c_library/CMakeLists.txt

# Set the minimum version of CMake required to build the project
cmake_minimum_required(VERSION 3.20)

# Set the name of the project and the language it is written in
project(C_Callback C)

# create a shared library
add_library(C_Callback SHARED)

# add the include directory to the library
target_include_directories(C_Callback PUBLIC include)

# add the sources to the library
target_sources(C_Callback PRIVATE src/C_Callback.c)
