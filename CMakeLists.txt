# \file CMakeLists.txt
# \brief Top-Level CMake File Defining Build
# \authors Rolfe Power

cmake_minimum_required(VERSION 3.22.0)
project(CrtbpCpp
    LANGUAGES CXX
    VERSION 0.2.0)

find_package(Boost REQUIRED)

add_subdirectory(src)
add_subdirectory(test)