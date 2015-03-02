// Copyright (c) 2015 The Chrominion Authors (aka Chrominions). All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMINION_HTTP_SERVER_H_
#define CHROMINION_HTTP_SERVER_H_

#include "base/memory/scoped_ptr.h"
#include "base/memory/ref_counted.h"

namespace net {
class StreamSocket;
class TCPServerSocket;
class IOBuffer;
}

namespace chrominion {

class HttpServer
{
 public:
  HttpServer();
  ~HttpServer();

 private:
  void OnAccepted(int result);
  void OnRead(int result);
  void OnWrite(int result);

  scoped_ptr<net::StreamSocket> client_socket_;
  scoped_ptr<net::TCPServerSocket> socket_;
  scoped_refptr<net::IOBuffer> read_buffer_;
  scoped_refptr<net::IOBuffer> write_buffer_;
};

} // namespace chrominion

#endif // CHROMINION_HTTP_SERVER_H_
