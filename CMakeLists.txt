# Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.14)
project(group2)

# enable c++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Variables
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/test)

file(GLOB SOURCE_FILE ${SRC_DIR}/*.cpp)
file(GLOB HEADER_FILE ${SRC_DIR}/include/*.h)
file(GLOB TEST_SOURCE_FILE ${TEST_DIR}/*.cpp)
file(GLOB MAIN_FILE ${PROJECT_SOURCE_DIR}/main.cpp)

# boost
option(Boost_USE_STATIC_LIBS ON)
option(Boost_USE_MULTITHREAD ON)
option(Boost_USE_STATIC_RUNTIME ON)
option(Boost_USE_DEBUG_RUNTIME ON)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS}) 
link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

# bulid src
add_subdirectory(${SRC_DIR})

# build test
# enable_testing()
# add_subdirectory(${TEST_DIR})