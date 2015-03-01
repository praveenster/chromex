// Copyright (c) 2015 The Chrominion Authors (aka Chrominions). All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrominion/server_process.h"
#include "base/at_exit.h"
#include "base/bind.h"
#include "base/run_loop.h"
#include "chrominion/http_server.h"

namespace chrominion {
ServerProcess* g_server_process = NULL;

ServerProcess::ServerProcess()
  : Thread("chrominion"),
    http_server_() {
}

ServerProcess::~ServerProcess() {
}

void ServerProcess::Launch() {
  if (g_server_process == NULL) {
    scoped_ptr<base::AtExitManager> at_exit_manager(new base::AtExitManager);
    Thread::Options options;
    options.message_loop_type = base::MessageLoop::TYPE_IO;
    g_server_process = new ServerProcess();
    g_server_process->StartWithOptions(options);
    g_server_process->message_loop()->PostTask(FROM_HERE, base::Bind(&ServerProcess::LiftOff, 
      base::Unretained(g_server_process)));

    base::MessageLoopForIO message_loop;
    base::RunLoop().Run();
  }
}

void ServerProcess::LiftOff() {
  http_server_.reset(new HttpServer());
}

} // namespace chrominion
