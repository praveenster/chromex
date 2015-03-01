// Copyright (c) 2015 The Chrominion Authors (aka Chrominions). All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <cstdio>
#include "chrominion/http_server.h"
#include "net/socket/tcp_server_socket.h"
#include "net/socket/stream_socket.h"

namespace chrominion {

HttpServer::HttpServer() {
  socket_.reset(new net::TCPServerSocket(NULL, net::NetLog::Source()));
  socket_->ListenWithAddressAndPort("127.0.0.1", 8080, 10);
  socket_->Accept(&client_socket_, base::Bind(&HttpServer::OnAccepted, base::Unretained(this)));
}

HttpServer::~HttpServer() {
}

void HttpServer::OnAccepted(int result)
{
  printf("value = %d\n", result);
};

} // namespace chrominion
