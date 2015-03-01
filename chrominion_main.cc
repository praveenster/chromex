// Copyright (c) 2015 The Chrominion Authors (aka Chrominions). All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrominion/server_process.h"

int main(int argc, char const *argv[])
{
  chrominion::ServerProcess::Launch();
  return 0;
}
