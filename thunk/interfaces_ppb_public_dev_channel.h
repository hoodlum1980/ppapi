// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Please see inteface_ppb_public_stable for the documentation on the format of
// this file.

#include "ppapi/thunk/interfaces_preamble.h"

// Interfaces go here.
PROXIED_IFACE(PPB_FILEREF_INTERFACE_1_2, PPB_FileRef_1_2)
PROXIED_IFACE(PPB_MEDIASTREAMVIDEOTRACK_INTERFACE_0_1,
              PPB_MediaStreamVideoTrack_0_1)
PROXIED_IFACE(PPB_VIDEOFRAME_INTERFACE_0_1, PPB_VideoFrame_0_1)

#include "ppapi/thunk/interfaces_postamble.h"
