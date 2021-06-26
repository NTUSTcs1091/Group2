# Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.14)

find_package(GTest)

if(GTEST_FOUND)
  add_executable(unit_tests 
    ${HEADER_FILE} 
    ${SOURCE_FILE} 
    ${TEST_SOURCE_FILE}
  )

  target_link_libraries(unit_tests 
    PUBLIC
      ${GTEST_BOTH_LIBRARIES} 
      pthread
  )

  target_include_directories(unit_tests 
    PUBLIC
      ${GTEST_INCLUDE_DIRS}
      ${SRC_DIR}/include
  )

  gtest_discover_tests(unit_tests)
endif()
