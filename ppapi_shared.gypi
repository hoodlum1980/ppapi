# Copyright (c) 2012 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
  'variables': {
    'conditions': [
      ['inside_chromium_build==0', {
        'webkit_src_dir': '../../../..',
      },{
        'webkit_src_dir': '../third_party/WebKit',
      }],
    ],
  },
  'target_defaults': {
    'variables': {
      'ppapi_shared_target': 0,
    },
    'target_conditions': [
      # This part is shared between the targets defined below.
      ['ppapi_shared_target==1', {
        'sources': [
          'shared_impl/array_writer.cc',
          'shared_impl/array_writer.h',
          'shared_impl/callback_tracker.cc',
          'shared_impl/callback_tracker.h',
          'shared_impl/file_path.cc',
          'shared_impl/file_path.h',
          'shared_impl/file_type_conversion.cc',
          'shared_impl/file_type_conversion.h',
          'shared_impl/host_resource.h',
          'shared_impl/id_assignment.cc',
          'shared_impl/id_assignment.h',
          'shared_impl/platform_file.cc',
          'shared_impl/platform_file.h',
          'shared_impl/ppapi_globals.cc',
          'shared_impl/ppapi_globals.h',
          'shared_impl/ppapi_preferences.cc',
          'shared_impl/ppapi_preferences.h',
          'shared_impl/ppb_audio_config_shared.cc',
          'shared_impl/ppb_audio_config_shared.h',
          'shared_impl/ppb_audio_input_shared.cc',
          'shared_impl/ppb_audio_input_shared.h',
          'shared_impl/ppb_audio_shared.cc',
          'shared_impl/ppb_audio_shared.h',
          'shared_impl/ppb_crypto_shared.cc',
          'shared_impl/ppb_device_ref_shared.cc',
          'shared_impl/ppb_device_ref_shared.h',
          'shared_impl/ppb_file_io_shared.cc',
          'shared_impl/ppb_file_io_shared.h',
          'shared_impl/ppb_file_ref_shared.cc',
          'shared_impl/ppb_file_ref_shared.h',
          'shared_impl/ppb_flash_shared.cc',
          'shared_impl/ppb_flash_shared.h',
          'shared_impl/ppb_graphics_3d_shared.cc',
          'shared_impl/ppb_graphics_3d_shared.h',
          'shared_impl/ppb_image_data_shared.cc',
          'shared_impl/ppb_image_data_shared.h',
          'shared_impl/ppb_input_event_shared.cc',
          'shared_impl/ppb_input_event_shared.h',
          'shared_impl/ppb_instance_shared.cc',
          'shared_impl/ppb_instance_shared.h',
          'shared_impl/ppb_memory_shared.cc',
          'shared_impl/ppb_network_list_private_shared.cc',
          'shared_impl/ppb_network_list_private_shared.h',
          'shared_impl/ppb_opengles2_shared.cc',
          'shared_impl/ppb_opengles2_shared.h',
          'shared_impl/ppb_resource_array_shared.cc',
          'shared_impl/ppb_resource_array_shared.h',
          'shared_impl/ppb_url_request_info_shared.cc',
          'shared_impl/ppb_url_request_info_shared.h',
          'shared_impl/ppb_url_util_shared.cc',
          'shared_impl/ppb_url_util_shared.h',
          'shared_impl/ppb_var_shared.cc',
          'shared_impl/ppb_var_shared.h',
          'shared_impl/ppb_video_decoder_shared.cc',
          'shared_impl/ppb_video_decoder_shared.h',
          'shared_impl/ppb_video_capture_shared.cc',
          'shared_impl/ppb_video_capture_shared.h',
          'shared_impl/ppb_view_shared.cc',
          'shared_impl/ppb_view_shared.h',
          'shared_impl/ppp_flash_browser_operations_shared.h',
          'shared_impl/ppp_instance_combined.cc',
          'shared_impl/ppp_instance_combined.h',
          'shared_impl/proxy_lock.cc',
          'shared_impl/proxy_lock.h',
          'shared_impl/resource.cc',
          'shared_impl/resource.h',
          'shared_impl/resource_tracker.cc',
          'shared_impl/resource_tracker.h',
          'shared_impl/scoped_pp_resource.cc',
          'shared_impl/scoped_pp_resource.h',
          'shared_impl/scoped_pp_var.cc',
          'shared_impl/scoped_pp_var.h',
          'shared_impl/time_conversion.cc',
          'shared_impl/time_conversion.h',
          'shared_impl/tracked_callback.cc',
          'shared_impl/tracked_callback.h',
          'shared_impl/var.cc',
          'shared_impl/var.h',
          'shared_impl/var_tracker.cc',
          'shared_impl/var_tracker.h',
          # TODO(viettrungluu): Split these out; it won't be used in NaCl.
          'shared_impl/private/net_address_private_impl.cc',
          'shared_impl/private/net_address_private_impl.h',

          'shared_impl/private/ppb_browser_font_trusted_shared.cc',
          'shared_impl/private/ppb_browser_font_trusted_shared.h',
          'shared_impl/private/ppb_char_set_shared.cc',
          'shared_impl/private/ppb_char_set_shared.h',
          'shared_impl/private/ppb_host_resolver_shared.cc',
          'shared_impl/private/ppb_host_resolver_shared.h',
          'shared_impl/private/ppb_tcp_server_socket_shared.cc',
          'shared_impl/private/ppb_tcp_server_socket_shared.h',
          'shared_impl/private/ppb_x509_certificate_private_shared.cc',
          'shared_impl/private/ppb_x509_certificate_private_shared.h',
          'shared_impl/private/tcp_socket_private_impl.cc',
          'shared_impl/private/tcp_socket_private_impl.h',
          'shared_impl/private/udp_socket_private_impl.cc',
          'shared_impl/private/udp_socket_private_impl.h',

          'thunk/enter.cc',
          'thunk/enter.h',
          'thunk/ppb_audio_api.h',
          'thunk/ppb_audio_config_api.h',
          'thunk/ppb_audio_config_thunk.cc',
          'thunk/ppb_audio_input_api.h',
          'thunk/ppb_audio_input_thunk.cc',
          'thunk/ppb_audio_input_trusted_thunk.cc',
          'thunk/ppb_audio_thunk.cc',
          'thunk/ppb_audio_trusted_thunk.cc',
          'thunk/ppb_broker_api.h',
          'thunk/ppb_broker_thunk.cc',
          'thunk/ppb_browser_font_trusted_api.h',
          'thunk/ppb_browser_font_trusted_thunk.cc',
          'thunk/ppb_buffer_api.h',
          'thunk/ppb_buffer_thunk.cc',
          'thunk/ppb_buffer_trusted_api.h',
          'thunk/ppb_buffer_trusted_thunk.cc',
          'thunk/ppb_char_set_thunk.cc',
          'thunk/ppb_console_thunk.cc',
          'thunk/ppb_cursor_control_thunk.cc',
          'thunk/ppb_device_ref_api.h',
          'thunk/ppb_device_ref_thunk.cc',
          'thunk/ppb_directory_reader_api.h',
          'thunk/ppb_directory_reader_thunk.cc',
          'thunk/ppb_file_chooser_api.h',
          'thunk/ppb_file_chooser_thunk.cc',
          'thunk/ppb_file_io_api.h',
          'thunk/ppb_file_io_thunk.cc',
          'thunk/ppb_file_io_trusted_thunk.cc',
          'thunk/ppb_file_ref_api.h',
          'thunk/ppb_file_ref_thunk.cc',
          'thunk/ppb_file_system_api.h',
          'thunk/ppb_file_system_thunk.cc',
          'thunk/ppb_find_thunk.cc',
          'thunk/ppb_flash_api.h',
          'thunk/ppb_flash_clipboard_thunk.cc',
          'thunk/ppb_flash_device_id_api.h',
          'thunk/ppb_flash_device_id_thunk.cc',
          'thunk/ppb_flash_file_fileref_thunk.cc',
          'thunk/ppb_flash_file_modulelocal_thunk.cc',
          'thunk/ppb_flash_fullscreen_thunk.cc',
          'thunk/ppb_flash_menu_api.h',
          'thunk/ppb_flash_menu_thunk.cc',
          'thunk/ppb_flash_message_loop_api.h',
          'thunk/ppb_flash_message_loop_thunk.cc',
          'thunk/ppb_flash_thunk.cc',
          'thunk/ppb_fullscreen_thunk.cc',
          'thunk/ppb_gamepad_thunk.cc',
          'thunk/ppb_gles_chromium_texture_mapping_thunk.cc',
          'thunk/ppb_graphics_2d_api.h',
          'thunk/ppb_graphics_2d_thunk.cc',
          'thunk/ppb_graphics_3d_api.h',
          'thunk/ppb_graphics_3d_thunk.cc',
          'thunk/ppb_graphics_3d_trusted_thunk.cc',
          'thunk/ppb_host_resolver_private_api.h',
          'thunk/ppb_host_resolver_private_thunk.cc',
          'thunk/ppb_image_data_api.h',
          'thunk/ppb_image_data_thunk.cc',
          'thunk/ppb_image_data_trusted_thunk.cc',
          'thunk/ppb_input_event_api.h',
          'thunk/ppb_input_event_thunk.cc',
          'thunk/ppb_instance_api.h',
          'thunk/ppb_instance_thunk.cc',
          'thunk/ppb_layer_compositor_api.h',
          'thunk/ppb_layer_compositor_thunk.cc',
          'thunk/ppb_message_loop_api.h',
          'thunk/ppb_messaging_thunk.cc',
          'thunk/ppb_mouse_cursor_thunk.cc',
          'thunk/ppb_mouse_lock_thunk.cc',
          'thunk/ppb_network_list_private_api.h',
          'thunk/ppb_network_list_private_thunk.cc',
          'thunk/ppb_network_monitor_private_api.h',
          'thunk/ppb_network_monitor_private_thunk.cc',
          'thunk/ppb_pdf_api.h',
          'thunk/ppb_printing_thunk.cc',
          'thunk/ppb_resource_array_api.h',
          'thunk/ppb_resource_array_thunk.cc',
          'thunk/ppb_scrollbar_api.h',
          'thunk/ppb_scrollbar_thunk.cc',
          'thunk/ppb_talk_private_api.h',
          'thunk/ppb_talk_private_thunk.cc',
          'thunk/ppb_tcp_server_socket_private_api.h',
          'thunk/ppb_tcp_server_socket_private_thunk.cc',
          'thunk/ppb_tcp_socket_private_api.h',
          'thunk/ppb_tcp_socket_private_thunk.cc',
          'thunk/ppb_text_input_thunk.cc',
          'thunk/ppb_udp_socket_private_api.h',
          'thunk/ppb_udp_socket_private_thunk.cc',
          'thunk/ppb_url_loader_api.h',
          'thunk/ppb_url_loader_thunk.cc',
          'thunk/ppb_url_request_info_api.h',
          'thunk/ppb_url_request_info_thunk.cc',
          'thunk/ppb_url_response_info_api.h',
          'thunk/ppb_url_response_info_thunk.cc',
          'thunk/ppb_url_util_thunk.cc',
          'thunk/ppb_video_capture_api.h',
          'thunk/ppb_video_capture_thunk.cc',
          'thunk/ppb_video_decoder_api.h',
          'thunk/ppb_video_decoder_thunk.cc',
          'thunk/ppb_video_layer_api.h',
          'thunk/ppb_video_layer_thunk.cc',
          'thunk/ppb_view_api.h',
          'thunk/ppb_view_thunk.cc',
          'thunk/ppb_websocket_api.h',
          'thunk/ppb_websocket_thunk.cc',
          'thunk/ppb_widget_api.h',
          'thunk/ppb_widget_thunk.cc',
          'thunk/ppb_x509_certificate_private_api.h',
          'thunk/ppb_x509_certificate_private_thunk.cc',
          'thunk/ppb_zoom_thunk.cc',
          'thunk/thunk.h',
        ],
        'defines': [
          'PPAPI_SHARED_IMPLEMENTATION',
          'PPAPI_THUNK_IMPLEMENTATION',
        ],
        'include_dirs': [
          '..',
        ],
        'target_conditions': [
          ['>(nacl_untrusted_build)==1', {
            'sources!': [
              'shared_impl/ppb_audio_input_shared.cc',
              'shared_impl/ppb_graphics_3d_shared.cc',
              'shared_impl/ppb_image_data_shared.cc',
              'shared_impl/ppb_opengles2_shared.cc',
              'shared_impl/ppb_url_util_shared.cc',
              'shared_impl/ppb_video_decoder_shared.cc',
              'shared_impl/ppb_video_capture_shared.cc',
              'shared_impl/private/net_address_private_impl.cc',
              'shared_impl/private/ppb_browser_font_trusted_shared.cc',
              'shared_impl/private/ppb_char_set_shared.cc',
              'shared_impl/private/ppb_host_resolver_shared.cc',
              'shared_impl/private/ppb_tcp_server_socket_shared.cc',
              'shared_impl/private/ppb_x509_certificate_private_shared.cc',
              'shared_impl/private/tcp_socket_private_impl.cc',
              'shared_impl/private/udp_socket_private_impl.cc',
              'thunk/ppb_audio_input_thunk.cc',
              'thunk/ppb_audio_input_trusted_thunk.cc',
              'thunk/ppb_audio_trusted_thunk.cc',
              'thunk/ppb_broker_thunk.cc',
              'thunk/ppb_browser_font_trusted_thunk.cc',
              'thunk/ppb_buffer_thunk.cc',
              'thunk/ppb_buffer_trusted_thunk.cc',
              'thunk/ppb_char_set_thunk.cc',
              'thunk/ppb_directory_reader_thunk.cc',
              'thunk/ppb_file_chooser_thunk.cc',
              'thunk/ppb_file_io_trusted_thunk.cc',
              'thunk/ppb_flash_clipboard_thunk.cc',
              'thunk/ppb_flash_device_id_thunk.cc',
              'thunk/ppb_flash_file_fileref_thunk.cc',
              'thunk/ppb_flash_file_modulelocal_thunk.cc',
              'thunk/ppb_flash_fullscreen_thunk.cc',
              'thunk/ppb_flash_menu_thunk.cc',
              'thunk/ppb_flash_message_loop_thunk.cc',
              'thunk/ppb_flash_thunk.cc',
              'thunk/ppb_flash_message_loop_thunk.cc',
              'thunk/ppb_gles_chromium_texture_mapping_thunk.cc',
              'thunk/ppb_graphics_2d_thunk.cc',
              'thunk/ppb_graphics_3d_thunk.cc',
              'thunk/ppb_graphics_3d_trusted_thunk.cc',
              'thunk/ppb_host_resolver_private_thunk.cc',
              'thunk/ppb_image_data_trusted_thunk.cc',
              'thunk/ppb_layer_compositor_thunk.cc',
              'thunk/ppb_network_list_private_thunk.cc',
              'thunk/ppb_network_monitor_private_thunk.cc',
              'thunk/ppb_scrollbar_thunk.cc',
              'thunk/ppb_talk_private_thunk.cc',
              'thunk/ppb_tcp_server_socket_private_thunk.cc',
              'thunk/ppb_tcp_socket_private_thunk.cc',
              'thunk/ppb_transport_thunk.cc',
              'thunk/ppb_udp_socket_private_thunk.cc',
              'thunk/ppb_url_util_thunk.cc',
              'thunk/ppb_video_capture_thunk.cc',
              'thunk/ppb_video_decoder_thunk.cc',
              'thunk/ppb_video_layer_thunk.cc',
              'thunk/ppb_websocket_thunk.cc',
              'thunk/ppb_x509_certificate_private_thunk.cc',
            ],
          }],
        ],
      }],
    ],
  },
}
