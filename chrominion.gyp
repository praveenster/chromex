# Copyright 2015 The Chrominion Authors (aka Chrominions). All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
  'targets': [
    {
      'target_name': 'chrominion',
      'type': 'executable',
      'dependencies': [
        '../base/base.gyp:base',
        '../net/net.gyp:net',
      ],
      'sources': [
        'chrominion_main.cc',
        'http_server.cc',
        'server_process.cc',
      ],
    },
  ],
}
