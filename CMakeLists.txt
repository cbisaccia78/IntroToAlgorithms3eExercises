cmake_minimum_required(VERSION 3.10)

# Project name
project(IntroToAlgorithmsSolutions)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Check if no build type is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Add utilities header
include_directories(${CMAKE_SOURCE_DIR})

# Automatically find and add all chapter subdirectories
file(GLOB SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/ch-*)

foreach(SUBDIR ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${SUBDIR})
        add_subdirectory(${SUBDIR})
    endif()
endforeach()