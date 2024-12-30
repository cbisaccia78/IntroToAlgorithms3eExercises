cmake_minimum_required(VERSION 3.10)

# Project name
project(IntroToAlgorithmsSolutions)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add utilities header
include_directories(${CMAKE_SOURCE_DIR})

# Automatically find and add all chapter subdirectories
file(GLOB SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/ch-*)

foreach(SUBDIR ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${SUBDIR})
        add_subdirectory(${SUBDIR})
    endif()
endforeach()