// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#ifndef _CLIENTMANAGER_H
#define _CLIENTMANAGER_H

class ClientManager {
public:
  thread_pool[] threadpool;

  void HandleAccept();

private:
  io_context context;
};

#endif  //_CLIENTMANAGER_H
