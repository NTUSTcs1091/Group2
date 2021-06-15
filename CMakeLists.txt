# Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.14)
project(group2)

set(CMAKE_CXX_STANDARD 11)

# Variables
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(SRC_DIR)

# header dir
include_directories(${SRC_DIR}/include)

# boost
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_MULTITHREAD ON)
SET(Boost_USE_STATIC_RUNTIME ON)
SET(Boost_USE_DEBUG_RUNTIME ON)

find_package(Boost REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()
