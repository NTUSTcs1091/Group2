// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _PACKET_H
#define _PACKET_H

#include <iostream>
#include <vector>

class Packet {
public:
  std::vector<char> data;

  void Operation1();

  void Operation2();
};

#endif  //_PACKET_H
