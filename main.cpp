// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include <iostream>
#include <string>

#include "Server.h"

int main(int argc, char *argv[]){
   std::cout << "Welcome to MyHttpServer!" << std::endl;
   std::string address = "127.0.0.1";
   uint16_t port = 9999;
   std::size_t max_session_count = 1000;
   std::size_t max_thread_count = 100;
   Server* server = Server::GetInstance(address, port, max_session_count, max_thread_count);
   return 0;
}
