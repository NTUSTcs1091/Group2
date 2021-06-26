# Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

cmake_minimum_required(VERSION 3.14)

add_executable(myhttpserver 
  ${HEADER_FILE} 
  ${MAIN_FILE} 
  ${SOURCE_FILE}
)

target_include_directories(myhttpserver 
  PUBLIC 
    ${SRC_DIR}/include
)
