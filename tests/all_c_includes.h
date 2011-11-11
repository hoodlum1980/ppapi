/* Copyright (c) 2011 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * This test simply includes all the C headers to ensure they compile with a C
 * compiler.  If it compiles, it passes.
 */
#ifndef PPAPI_TESTS_ALL_C_INCLUDES_H_
#define PPAPI_TESTS_ALL_C_INCLUDES_H_

#include "ppapi/c/dev/deprecated_bool.h"
#include "ppapi/c/dev/pp_cursor_type_dev.h"
#include "ppapi/c/dev/pp_video_dev.h"
#include "ppapi/c/dev/ppb_buffer_dev.h"
#include "ppapi/c/dev/ppb_char_set_dev.h"
#include "ppapi/c/dev/ppb_console_dev.h"
#include "ppapi/c/dev/ppb_context_3d_dev.h"
#include "ppapi/c/dev/ppb_context_3d_trusted_dev.h"
#include "ppapi/c/dev/ppb_crypto_dev.h"
#include "ppapi/c/dev/ppb_cursor_control_dev.h"
#include "ppapi/c/dev/ppb_directory_reader_dev.h"
#include "ppapi/c/dev/ppb_file_chooser_dev.h"
#include "ppapi/c/dev/ppb_find_dev.h"
#include "ppapi/c/dev/ppb_font_dev.h"
#include "ppapi/c/dev/ppb_fullscreen_dev.h"
#include "ppapi/c/dev/ppb_ime_input_event_dev.h"
#include "ppapi/c/dev/ppb_layer_compositor_dev.h"
#include "ppapi/c/dev/ppb_memory_dev.h"
#include "ppapi/c/dev/ppb_scrollbar_dev.h"
#include "ppapi/c/dev/ppb_surface_3d_dev.h"
#include "ppapi/c/dev/ppb_testing_dev.h"
#include "ppapi/c/dev/ppb_text_input_dev.h"
#include "ppapi/c/dev/ppb_transport_dev.h"
#include "ppapi/c/dev/ppb_url_util_dev.h"
#include "ppapi/c/dev/ppb_var_deprecated.h"
#include "ppapi/c/dev/ppb_video_decoder_dev.h"
#include "ppapi/c/dev/ppb_video_layer_dev.h"
#include "ppapi/c/dev/ppb_websocket_dev.h"
#include "ppapi/c/dev/ppb_widget_dev.h"
#include "ppapi/c/dev/ppb_zoom_dev.h"
#include "ppapi/c/dev/ppp_class_deprecated.h"
#include "ppapi/c/dev/ppp_cursor_control_dev.h"
#include "ppapi/c/dev/ppp_find_dev.h"
#include "ppapi/c/dev/ppp_printing_dev.h"
#include "ppapi/c/dev/ppp_scrollbar_dev.h"
#include "ppapi/c/dev/ppp_selection_dev.h"
#include "ppapi/c/dev/ppp_video_decoder_dev.h"
#include "ppapi/c/dev/ppp_widget_dev.h"
#include "ppapi/c/dev/ppp_zoom_dev.h"
#include "ppapi/c/trusted/ppb_file_io_trusted.h"
#include "ppapi/c/pp_bool.h"
#include "ppapi/c/pp_completion_callback.h"
#include "ppapi/c/pp_errors.h"
#include "ppapi/c/pp_file_info.h"
#include "ppapi/c/pp_graphics_3d.h"
#include "ppapi/c/pp_input_event.h"
#include "ppapi/c/pp_instance.h"
#include "ppapi/c/pp_macros.h"
#include "ppapi/c/pp_module.h"
#include "ppapi/c/pp_point.h"
#include "ppapi/c/pp_rect.h"
#include "ppapi/c/pp_resource.h"
#include "ppapi/c/pp_size.h"
#include "ppapi/c/pp_stdint.h"
#include "ppapi/c/pp_time.h"
#include "ppapi/c/pp_var.h"
#include "ppapi/c/ppb.h"
#include "ppapi/c/ppb_audio.h"
#include "ppapi/c/ppb_audio_config.h"
#include "ppapi/c/ppb_core.h"
#include "ppapi/c/ppb_file_io.h"
#include "ppapi/c/ppb_file_ref.h"
#include "ppapi/c/ppb_file_system.h"
#include "ppapi/c/ppb_fullscreen.h"
#include "ppapi/c/ppb_graphics_2d.h"
#include "ppapi/c/ppb_graphics_3d.h"
#include "ppapi/c/ppb_image_data.h"
#include "ppapi/c/ppb_input_event.h"
#include "ppapi/c/ppb_instance.h"
#include "ppapi/c/ppb_messaging.h"
#include "ppapi/c/ppb_mouse_lock.h"
#include "ppapi/c/ppb_opengles2.h"
#include "ppapi/c/ppb_url_loader.h"
#include "ppapi/c/ppb_url_request_info.h"
#include "ppapi/c/ppb_url_response_info.h"
#include "ppapi/c/ppp.h"
#include "ppapi/c/ppp_graphics_3d.h"
#include "ppapi/c/ppp_input_event.h"
#include "ppapi/c/ppp_instance.h"
#include "ppapi/c/ppp_messaging.h"
#include "ppapi/c/ppp_mouse_lock.h"
#include "ppapi/c/private/ppb_flash.h"
#include "ppapi/c/private/ppb_flash_menu.h"
#include "ppapi/c/private/ppb_flash_tcp_socket.h"
#include "ppapi/c/private/ppb_gpu_blacklist_private.h"
#include "ppapi/c/trusted/ppb_graphics_3d_trusted.h"
#include "ppapi/c/private/ppb_instance_private.h"
#include "ppapi/c/private/ppb_nacl_private.h"
#include "ppapi/c/private/ppb_pdf.h"
#include "ppapi/c/private/ppb_uma_private.h"
#include "ppapi/c/trusted/ppb_audio_trusted.h"
#include "ppapi/c/trusted/ppb_image_data_trusted.h"
#include "ppapi/c/trusted/ppb_url_loader_trusted.h"
#include "ppapi/c/private/ppp_instance_private.h"

#endif  /* PPAPI_TESTS_ALL_C_INCLUDES_H_ */
