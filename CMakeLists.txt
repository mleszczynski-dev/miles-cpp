cmake_minimum_required (VERSION 3.21.1)

project("miles-cpp" LANGUAGES CXX)

message(STATUS "Miles ver 1")

message(STATUS "C++ compiler path: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(cpp)
add_subdirectory(test)

