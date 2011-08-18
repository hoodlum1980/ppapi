// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ppapi/shared_impl/video_decoder_impl.h"

#include "base/logging.h"
#include "gpu/command_buffer/client/gles2_implementation.h"
#include "ppapi/c/pp_errors.h"
#include "ppapi/proxy/plugin_resource_tracker.h"
#include "ppapi/shared_impl/resource_tracker.h"
#include "ppapi/thunk/ppb_context_3d_api.h"
#include "ppapi/thunk/enter.h"

using ppapi::thunk::PPB_Context3D_API;

namespace ppapi {

VideoDecoderImpl::VideoDecoderImpl()
    : flush_callback_(PP_MakeCompletionCallback(NULL, NULL)),
      reset_callback_(PP_MakeCompletionCallback(NULL, NULL)),
      context3d_id_(0),
      gles2_impl_(NULL) {
}

VideoDecoderImpl::~VideoDecoderImpl() {
}

bool VideoDecoderImpl::Init(PP_Resource context3d_id,
                            PPB_Context3D_API* context3d,
                            const PP_VideoConfigElement* decoder_config) {
  if (!context3d || !decoder_config || !context3d_id)
    return false;

  DCHECK(!gles2_impl_ && !context3d_id_);
  gles2_impl_ = context3d->GetGLES2Impl();
  TrackerBase::Get()->GetResourceTracker()->AddRefResource(context3d_id);
  context3d_id_ = context3d_id;
  return true;
}

void VideoDecoderImpl::Destroy() {
  context3d_id_ = 0;
  gles2_impl_ = NULL;
  TrackerBase::Get()->GetResourceTracker()->ReleaseResource(context3d_id_);
}

bool VideoDecoderImpl::SetFlushCallback(PP_CompletionCallback callback) {
  CHECK(callback.func);
  if (flush_callback_.func)
    return false;
  flush_callback_ = callback;
  return true;
}

bool VideoDecoderImpl::SetResetCallback(PP_CompletionCallback callback) {
  CHECK(callback.func);
  if (reset_callback_.func)
    return false;
  reset_callback_ = callback;
  return true;
}

bool VideoDecoderImpl::SetBitstreamBufferCallback(
    int32 bitstream_buffer_id, PP_CompletionCallback callback) {
  return bitstream_buffer_callbacks_.insert(
      std::make_pair(bitstream_buffer_id, callback)).second;
}

void VideoDecoderImpl::RunFlushCallback(int32 result) {
  DCHECK(flush_callback_.func);
  PP_RunAndClearCompletionCallback(&flush_callback_, result);
}

void VideoDecoderImpl::RunResetCallback(int32 result) {
  DCHECK(reset_callback_.func);
  PP_RunAndClearCompletionCallback(&reset_callback_, result);
}

void VideoDecoderImpl::RunBitstreamBufferCallback(
    int32 bitstream_buffer_id, int32 result) {
  CallbackById::iterator it =
      bitstream_buffer_callbacks_.find(bitstream_buffer_id);
  DCHECK(it != bitstream_buffer_callbacks_.end());
  PP_CompletionCallback cc = it->second;
  bitstream_buffer_callbacks_.erase(it);
  PP_RunCompletionCallback(&cc, PP_OK);
}

void VideoDecoderImpl::FlushCommandBuffer() {
  if (gles2_impl_)
    gles2_impl_->Flush();
}

bool VideoDecoderImpl::CopyConfigsToVector(
    const PP_VideoConfigElement* configs_to_copy,
    std::vector<PP_VideoConfigElement>* out_configs) {
  // TODO(fischman/vrk): This is still broken. We need to get rid of the silly
  // PP_VideoConfigElement vector in favor of a struct (see TODO in
  // ppb_video_decoder_dev.h).
  const PP_VideoConfigElement* current = configs_to_copy;
  while (current && *current != PP_VIDEOATTR_DICTIONARY_TERMINATOR) {
    out_configs->push_back(*current);
    out_configs->push_back(*(current + 1));
    current += 2;
  }
  return true;
}

}  // namespace ppapi
