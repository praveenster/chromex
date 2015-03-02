// Copyright (c) 2015 The Chrominion Authors (aka Chrominions). All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <cstdio>
#include "chrominion/http_server.h"
#include "net/socket/tcp_server_socket.h"
#include "net/socket/stream_socket.h"
#include "net/base/io_buffer.h"

namespace chrominion {

HttpServer::HttpServer() {
  socket_.reset(new net::TCPServerSocket(NULL, net::NetLog::Source()));
  socket_->ListenWithAddressAndPort("127.0.0.1", 8080, 10);
  socket_->Accept(&client_socket_, base::Bind(&HttpServer::OnAccepted, base::Unretained(this)));
  read_buffer_ = new net::IOBuffer(4 * 1024);
  write_buffer_ = new net::IOBuffer(4 * 1024);
}

HttpServer::~HttpServer() {
}

void HttpServer::OnAccepted(int result) {
  printf("OnAccepted: value = %d\n", result);
  int result2 = client_socket_->Read(read_buffer_.get(), 4 * 1024, base::Bind(&HttpServer::OnRead, base::Unretained(this)));
  printf("result2 = %d\n", result2);
}

void HttpServer::OnRead(int result) {
  printf("OnRead result = %d\n", result);
  printf("OnRead: %s\n", read_buffer_.get()->data());

  char* b = write_buffer_.get()->data();
  sprintf(b, "HTTP/1.1 200 OK\r\n"
          "Date: Sun, 1 Mar 2015 21:38:00 GMT\r\n"
          "Server: chrominion\r\n"
          "Connection: close\r\n"
          "Content-Type: text/html\r\n"
          "Content-Length: 74\r\n"
          "\r\n"
          "<HTML><HEAD><TITLE>Welcome to our home!</TITLE></HEAD><BODY></BODY></HTML>");

  printf("Content-length = %d, Response = %s\n", strlen(b), b);

  client_socket_->Write(write_buffer_.get(), strlen(b), base::Bind(&HttpServer::OnWrite, base::Unretained(this)));
  //client_socket_->Disconnect();
}

void HttpServer::OnWrite(int result) {
  printf("OnWrite: result = %d\n", result);
}

} // namespace chrominion
