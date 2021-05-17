// Copyright (c) 2021 Pei-Ru Wang, Cheryl Huang, Yuan Zhou. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

/**
 * Project MyHttpServer
 * @author Pei-Ru Wang, Cheryl Huang, Yuan Zhou
 * @version 0.0.1
 */

#include "HttpRouterHandler.h"

std::unique_ptr<HttpRouterHandler> HttpRouterHandler::GetInstance() {
    static HttpRouterHandler instance;
    return std::make_unique<HttpRouterHandler>(instance);
}