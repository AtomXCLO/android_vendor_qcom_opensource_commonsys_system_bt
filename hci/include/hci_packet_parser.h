/******************************************************************************
 *
 *  Copyright (C) 2014 Google, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#pragma once

#include <stdint.h>

#include "bt_types.h"
#include "device_features.h"
#include "features.h"
#include "osi/include/allocator.h"
#include "version.h"

typedef struct {
  void (*parse_generic_command_complete)(BT_HDR* response);

  void (*parse_read_buffer_size_response)(BT_HDR* response,
                                          uint16_t* data_size_ptr,
                                          uint16_t* acl_buffer_count_ptr);

  void (*parse_read_local_version_info_response)(BT_HDR* response,
                                                 bt_version_t* bt_version_ptr);

  void (*parse_read_bd_addr_response)(BT_HDR* response,
                                      RawAddress* address_ptr);

  void (*parse_read_local_supported_commands_response)(
      BT_HDR* response, uint8_t* supported_commands_ptr,
      size_t supported_commands_length);

  void (*parse_read_local_extended_features_response)(
      BT_HDR* response, uint8_t* page_number_ptr, uint8_t* max_page_number_ptr,
      bt_device_features_t* feature_pages, size_t feature_pages_count);

  void (*parse_ble_read_white_list_size_response)(BT_HDR* response,
                                                  uint8_t* white_list_size_ptr);

  void (*parse_ble_read_buffer_size_response)(
      BT_HDR* response,
      uint16_t* le_acl_data_packet_length,
      uint8_t* total_num_le_acl_data_packets,
      uint16_t* iso_data_packet_length,
      uint8_t* total_num_iso_data_packets);


  void (*parse_ble_read_supported_states_response)(
      BT_HDR* response, uint8_t* supported_states,
      size_t supported_states_size);

  void (*parse_ble_read_local_supported_features_response)(
      BT_HDR* response, bt_device_features_t* supported_features);

  void (*parse_ble_read_resolving_list_size_response)(
      BT_HDR* response, uint8_t* resolving_list_size_ptr);

  void (*parse_ble_read_suggested_default_data_length_response)(
      BT_HDR* response, uint16_t* ble_default_packet_length_ptr);

  void (*parse_ble_read_maximum_advertising_data_length)(
      BT_HDR* response, uint16_t* ble_maximum_advertising_data_length_ptr);

  void (*parse_ble_read_number_of_supported_advertising_sets)(
      BT_HDR* response, uint8_t* ble_number_of_supported_advertising_sets_ptr);

  void (*parse_read_local_supported_codecs_response)(
      BT_HDR* response,
      uint8_t* number_of_std_supported_codecs,
      uint8_t* std_supported_codecs, uint8_t* std_codec_tx,
      uint8_t* number_of_vs_supported_codecs,
      uint32_t* vs_supported_codecs, uint8_t* vs_codec_tx);


  void (*parse_ble_read_offload_features_response)(
      BT_HDR *response,
      bool *ble_offload_features_supported);

  void (*parse_read_scrambling_supported_freqs_response)(
      BT_HDR* response, uint8_t* number_of_scrambling_supported_freqs,
      uint8_t* scrambling_supported_freqs);

  void (*parse_read_add_on_features_supported_response)(
      BT_HDR* response, bt_device_soc_add_on_features_t* supported_add_on_features,
      uint8_t *valid_bytes, uint16_t* product_id, uint16_t* response_version);

  void (*parse_read_local_simple_paring_options_response)(
      BT_HDR* response, uint8_t* simple_pairing_options,
      uint8_t* maximum_encryption_key_size);

  void (*parse_ble_set_host_feature_cmd)(BT_HDR* response);

  void (*parse_set_min_encryption_key_size_response)(BT_HDR* response);
  void (*parse_qll_read_local_supported_features_response)(BT_HDR* response,
                 bt_device_qll_local_supported_features_t* supported_features);

} hci_packet_parser_t;

const hci_packet_parser_t* hci_packet_parser_get_interface();

const hci_packet_parser_t* hci_packet_parser_get_test_interface(
    allocator_t* buffer_allocator_interface);
