/* Copyright (c) 2012 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* From private/ppp_content_decryptor_private.idl,
 *   modified Mon Oct  8 13:45:19 2012.
 */

#ifndef PPAPI_C_PRIVATE_PPP_CONTENT_DECRYPTOR_PRIVATE_H_
#define PPAPI_C_PRIVATE_PPP_CONTENT_DECRYPTOR_PRIVATE_H_

#include "ppapi/c/pp_bool.h"
#include "ppapi/c/pp_instance.h"
#include "ppapi/c/pp_macros.h"
#include "ppapi/c/pp_resource.h"
#include "ppapi/c/pp_stdint.h"
#include "ppapi/c/pp_var.h"
#include "ppapi/c/private/pp_content_decryptor.h"

#define PPP_CONTENTDECRYPTOR_PRIVATE_INTERFACE_0_3 \
    "PPP_ContentDecryptor_Private;0.3"
#define PPP_CONTENTDECRYPTOR_PRIVATE_INTERFACE \
    PPP_CONTENTDECRYPTOR_PRIVATE_INTERFACE_0_3

/**
 * @file
 * This file defines the <code>PPP_ContentDecryptor_Private</code>
 * interface. Note: This is a special interface, only to be used for Content
 * Decryption Modules, not normal plugins.
 */


/**
 * @addtogroup Interfaces
 * @{
 */
/**
 * <code>PPP_ContentDecryptor_Private</code> structure contains the function
 * pointers the decryption plugin must implement to provide services needed by
 * the browser. This interface provides the plugin side support for the Content
 * Decryption Module (CDM) for v0.1 of the proposed Encrypted Media Extensions:
 * http://goo.gl/rbdnR
 */
struct PPP_ContentDecryptor_Private_0_3 {
  /**
   * Generates a key request. key_system specifies the key or licensing system
   * to use. init_data is a data buffer containing data for use in generating
   * the request.
   *
   * Note: <code>GenerateKeyRequest()</code> must create the session ID used in
   * other methods on this interface. The session ID must be provided to the
   * browser by the CDM via <code>KeyMessage()</code> on the
   * <code>PPB_ContentDecryptor_Private</code> interface.
   *
   * @param[in] key_system A <code>PP_Var</code> of type
   * <code>PP_VARTYPE_STRING</code> containing the name of the key system.
   *
   * @param[in] init_data A <code>PP_Var</code> of type
   * <code>PP_VARTYPE_ARRAYBUFFER</code> containing container specific
   * initialization data.
   */
  void (*GenerateKeyRequest)(PP_Instance instance,
                             struct PP_Var key_system,
                             struct PP_Var init_data);
  /**
   * Provides a key or license to the decryptor for decrypting media data.
   *
   * When the CDM needs more information to complete addition of the key it
   * will call <code>KeyMessage()</code> on the
   * <code>PPB_ContentDecryptor_Private</code> interface, which the browser
   * passes to the application. When the key is ready to use, the CDM
   * must call call <code>KeyAdded()</code> on the
   * <code>PPB_ContentDecryptor_Private</code> interface, and the browser
   * must notify the web application.
   *
   * @param[in] session_id A <code>PP_Var</code> of type
   * <code>PP_VARTYPE_STRING</code> containing the session ID.
   *
   * @param[in] key A <code>PP_Var</code> of type
   * <code>PP_VARTYPE_ARRAYBUFFER</code> containing the decryption key, license,
   * or other message for the given session ID.
   *
   * @param[in] init_data A <code>PP_Var</code> of type
   * <code>PP_VARTYPE_ARRAYBUFFER</code> containing container specific
   * initialization data.
   */
  void (*AddKey)(PP_Instance instance,
                 struct PP_Var session_id,
                 struct PP_Var key,
                 struct PP_Var init_data);
  /**
   * Cancels a pending key request for the specified session ID.
   *
   * @param[in] session_id A <code>PP_Var</code> of type
   * <code>PP_VARTYPE_STRING</code> containing the session ID.
   */
  void (*CancelKeyRequest)(PP_Instance instance, struct PP_Var session_id);
  /**
   * Decrypts the block and returns the unencrypted block via
   * <code>DeliverBlock()</code> on the
   * <code>PPB_ContentDecryptor_Private</code> interface. The returned block
   * contains encoded data.
   *
   * @param[in] resource A <code>PP_Resource</code> corresponding to a
   * <code>PPB_Buffer_Dev</code> resource that contains an encrypted data
   * block.
   *
   * @param[in] encrypted_block_info A <code>PP_EncryptedBlockInfo</code> that
   * contains all auxiliary information needed for decryption of the
   * <code>encrypted_block</code>.
   */
  void (*Decrypt)(PP_Instance instance,
                  PP_Resource encrypted_block,
                  const struct PP_EncryptedBlockInfo* encrypted_block_info);
  /**
   * Initializes the video decoder using codec and settings in
   * <code>decoder_config</code>, and returns the result of the initialization
   * request to the browser using the <code>DecoderInitialized()</code> method
   * on the <code>PPB_ContentDecryptor_Private</code> interface.
   *
   * @param[in] decoder_config A <code>PP_VideoDecoderConfig</code> that
   * contains video decoder settings and a request ID. The request ID is passed
   * to the <code>DecoderInitialized()</code> method on the
   * <code>PPB_ContentDecryptor_Private</code> interface to allow clients to
   * associate the result with a video decoder initialization request.
   *
   * @param[in] codec_extra_data A <code>PP_Resource</code> corresponding to a
   * <code>PPB_Buffer_Dev</code> resource containing codec setup data required
   * by some codecs. It should be set to 0 when the codec being initialized
   * does not require it.
   */
  void (*InitializeVideoDecoder)(
      PP_Instance instance,
      const struct PP_VideoDecoderConfig* decoder_config,
      PP_Resource codec_extra_data);
  /**
   * Decrypts encrypted_video_frame, decodes it, and returns the unencrypted
   * uncompressed (decoded) video frame to the browser via the
   * <code>DeliverFrame()</code> method on the
   * <code>PPB_ContentDecryptor_Private</code> interface.
   *
   * @param[in] encrypted_video_frame A <code>PP_Resource</code> corresponding
   * to a <code>PPB_Buffer_Dev</code> resource that contains an encrypted video
   * frame.
   *
   * @param[in] encrypted_video_frame_info A
   * <code>PP_EncryptedVideoFrameInfo</code> that contains all information
   * needed to decrypt and decode <code>encrypted_video_frame</code>.
   */
  void (*DecryptAndDecodeFrame)(
      PP_Instance instance,
      PP_Resource encrypted_video_frame,
      const struct PP_EncryptedVideoFrameInfo* encrypted_video_frame_info);
};

typedef struct PPP_ContentDecryptor_Private_0_3 PPP_ContentDecryptor_Private;
/**
 * @}
 */

#endif  /* PPAPI_C_PRIVATE_PPP_CONTENT_DECRYPTOR_PRIVATE_H_ */

