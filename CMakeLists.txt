if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
    FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
    ")
endif()

cmake_minimum_required (VERSION 3.0)
project(LeetCode)

set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")
set(CMAKE_VERBOSE_MAKEFILE on)

ADD_DEFINITIONS("-std=c++11")
ADD_DEFINITIONS("-Wall -g -DDEBUG")

ADD_SUBDIRECTORY(Problems)