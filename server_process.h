// Copyright (c) 2015 The Chrominion Authors (aka Chrominions). All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMINION_SERVER_PROCESS_H_
#define CHROMINION_SERVER_PROCESS_H_

#include "base/threading/thread.h"

namespace chrominion {
class HttpServer;
}

namespace chrominion {

class ServerProcess : public base::Thread {
 public:
  ServerProcess();
  ~ServerProcess() override;

  static void Launch();

 private:
  void LiftOff();
  scoped_ptr<HttpServer> http_server_;
};

} // namespace chrominion

#endif // CHROMINION_SERVER_PROCESS_H_
