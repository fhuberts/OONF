
/*
 * The olsr.org Optimized Link-State Routing daemon version 2 (olsrd2)
 * Copyright (c) 2004-2013, the olsr.org team - see HISTORY file
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of olsr.org, olsrd nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Visit http://www.olsr.org for more information.
 *
 * If you find this software useful feel free to make a donation
 * to the project. For more information see the website or contact
 * the copyright holders.
 *
 */

#ifndef OONF_LAYER2_H_
#define OONF_LAYER2_H_

#include "common/avl.h"
#include "common/common_types.h"
#include "core/oonf_subsystem.h"
#include "subsystems/oonf_interface.h"

#define OONF_LAYER2_SUBSYSTEM "layer2"

#define LAYER2_CLASS_NEIGHBOR    "layer2_neighbor"
#define LAYER2_CLASS_NETWORK     "layer2_network"
#define LAYER2_CLASS_DESTINATION "layer2_destination"

#define OONF_LAYER2_NET_LAST_SEEN_KEY        "last_seen"
#define OONF_LAYER2_NET_FREQUENCY_1_KEY      "frequency1"
#define OONF_LAYER2_NET_FREQUENCY_2_KEY      "frequency2"
#define OONF_LAYER2_NET_BANDWIDTH_1_KEY      "bandwidth1"
#define OONF_LAYER2_NET_BANDWIDTH_2_KEY      "bandwidth2"
#define OONF_LAYER2_NET_NOISE_KEY            "noise"
#define OONF_LAYER2_NET_CHANNEL_ACTIVE_KEY   "ch_active"
#define OONF_LAYER2_NET_CHANNEL_BUSY_KEY     "ch_busy"
#define OONF_LAYER2_NET_CHANNEL_BUSYEXT_KEY  "ch_ext_busy"
#define OONF_LAYER2_NET_CHANNEL_RX_KEY       "ch_rx"
#define OONF_LAYER2_NET_CHANNEL_TX_KEY       "ch_tx"

#define OONF_LAYER2_NEIGH_LAST_SEEN_KEY      "last_seen"
#define OONF_LAYER2_NEIGH_RX_SIGNAL_KEY      "rx_signal"
#define OONF_LAYER2_NEIGH_TX_SIGNAL_KEY      "tx_signal"
#define OONF_LAYER2_NEIGH_TX_BITRATE_KEY     "tx_bitrate"
#define OONF_LAYER2_NEIGH_RX_BITRATE_KEY     "rx_bitrate"
#define OONF_LAYER2_NEIGH_TX_MAX_BITRATE_KEY "tx_max_bitrate"
#define OONF_LAYER2_NEIGH_RX_MAX_BITRATE_KEY "rx_max_bitrate"
#define OONF_LAYER2_NEIGH_TX_BYTES_KEY       "tx_bytes"
#define OONF_LAYER2_NEIGH_RX_BYTES_KEY       "rx_bytes"
#define OONF_LAYER2_NEIGH_TX_FRAMES_KEY      "tx_frames"
#define OONF_LAYER2_NEIGH_RX_FRAMES_KEY      "rx_frames"
#define OONF_LAYER2_NEIGH_TX_THROUGHPUT_KEY  "tx_throughput"
#define OONF_LAYER2_NEIGH_TX_RETRIES_KEY     "tx_retries"
#define OONF_LAYER2_NEIGH_TX_FAILED_KEY      "tx_failed"

struct oonf_layer2_data {
  int64_t _value;
  bool _has_value;
  uint32_t _origin;
};

enum oonf_layer2_network_index {
  OONF_LAYER2_NET_FREQUENCY_1,
  OONF_LAYER2_NET_FREQUENCY_2,
  OONF_LAYER2_NET_BANDWIDTH_1,
  OONF_LAYER2_NET_BANDWIDTH_2,
  OONF_LAYER2_NET_NOISE,
  OONF_LAYER2_NET_CHANNEL_ACTIVE,
  OONF_LAYER2_NET_CHANNEL_BUSY,
  OONF_LAYER2_NET_CHANNEL_BUSYEXT,
  OONF_LAYER2_NET_CHANNEL_RX,
  OONF_LAYER2_NET_CHANNEL_TX,

  /* last entry */
  OONF_LAYER2_NET_COUNT,
};

enum oonf_layer2_network_type {
  OONF_LAYER2_TYPE_UNDEFINED,
  OONF_LAYER2_TYPE_WIRELESS,
  OONF_LAYER2_TYPE_ETHERNET,
  OONF_LAYER2_TYPE_TUNNEL,
  OONF_LAYER2_TYPE_DLEP,

  OONF_LAYER2_TYPE_COUNT,
};

enum oonf_layer2_neighbor_index {
  OONF_LAYER2_NEIGH_TX_SIGNAL,
  OONF_LAYER2_NEIGH_RX_SIGNAL,
  OONF_LAYER2_NEIGH_TX_BITRATE,
  OONF_LAYER2_NEIGH_RX_BITRATE,
  OONF_LAYER2_NEIGH_TX_MAX_BITRATE,
  OONF_LAYER2_NEIGH_RX_MAX_BITRATE,
  OONF_LAYER2_NEIGH_TX_BYTES,
  OONF_LAYER2_NEIGH_RX_BYTES,
  OONF_LAYER2_NEIGH_TX_FRAMES,
  OONF_LAYER2_NEIGH_RX_FRAMES,
  OONF_LAYER2_NEIGH_TX_THROUGHPUT,
  OONF_LAYER2_NEIGH_TX_RETRIES,
  OONF_LAYER2_NEIGH_TX_FAILED,

  /* last entry */
  OONF_LAYER2_NEIGH_COUNT,
};

struct oonf_layer2_net {
  /* name of local interface */
  char name[IF_NAMESIZE];

  /* optional identification string */
  char if_ident[64];

  /* interface type */
  enum oonf_layer2_network_type if_type;

  /* interface listener to keep track of events and local mac address */
  struct oonf_interface_listener if_listener;

  /* tree of remote neighbors */
  struct avl_tree neighbors;

  /* absolute timestamp when network has been active last */
  uint64_t last_seen;

  /* network wide layer 2 data */
  struct oonf_layer2_data data[OONF_LAYER2_NET_COUNT];

  /* default values of neighbor layer2 data */
  struct oonf_layer2_data neighdata[OONF_LAYER2_NEIGH_COUNT];

  /* node to hook into global l2network tree */
  struct avl_node _node;
};

struct oonf_layer2_neigh {
  /* remote mac address of neighbor */
  struct netaddr addr;

  /* back pointer to layer2 network */
  struct oonf_layer2_net *network;

  /* tree of proxied destinations */
  struct avl_tree destinations;

  /* absolute timestamp when neighbor has been active last */
  uint64_t last_seen;

  /* neigbor layer 2 data */
  struct oonf_layer2_data data[OONF_LAYER2_NEIGH_COUNT];

  /* node to hook into tree of layer2 network */
  struct avl_node _node;
};

struct oonf_layer2_destination {
  /* proxied mac address behind a layer2 neighbor */
  struct netaddr destination;

  /* back pointer to layer2 neighbor */
  struct oonf_layer2_neigh *neighbor;

  /* origin of this proxied address */
  uint32_t origin;

  /* node to hook into tree of layer2 neighbor */
  struct avl_node _node;
};

struct oonf_layer2_metadata {
  /* type of data */
  const char key[16];

  /* unit (bit/s, byte, ...) */
  const char unit[8];

  /* number of fractional digits of the data */
  const int fraction;

  /* true if data is "base" 1024 instead of "base" 1000 */
  const bool binary;
};

EXPORT uint32_t oonf_layer2_register_origin(void);
EXPORT void oonf_layer2_cleanup_origin(uint32_t);

EXPORT struct oonf_layer2_net *oonf_layer2_net_add(const char *ifname);
EXPORT void oonf_layer2_net_remove(
    struct oonf_layer2_net *, uint32_t origin);
EXPORT bool oonf_layer2_net_cleanup(struct oonf_layer2_net *l2net, uint32_t origin);
EXPORT bool oonf_layer2_net_commit(struct oonf_layer2_net *);

EXPORT struct oonf_layer2_neigh *oonf_layer2_neigh_add(
    struct oonf_layer2_net *, struct netaddr *l2neigh);
EXPORT bool oonf_layer2_neigh_cleanup(struct oonf_layer2_neigh *l2neigh, uint32_t origin);
EXPORT void oonf_layer2_neigh_remove(
    struct oonf_layer2_neigh *l2neigh, uint32_t origin);

EXPORT bool oonf_layer2_neigh_commit(struct oonf_layer2_neigh *l2neigh);

EXPORT struct oonf_layer2_destination *oonf_layer2_destination_add(
    struct oonf_layer2_neigh *l2neigh, const struct netaddr *destination,
    uint32_t origin);
EXPORT void oonf_layer2_destination_remove(struct oonf_layer2_destination *);

EXPORT const struct oonf_layer2_data *oonf_layer2_neigh_query(
    const char *ifname, const struct netaddr *l2neigh,
    enum oonf_layer2_neighbor_index idx);
EXPORT const struct oonf_layer2_data *oonf_layer2_neigh_get_value(
    const struct oonf_layer2_neigh *l2neigh, enum oonf_layer2_neighbor_index idx);

EXPORT bool oonf_layer2_change_value(struct oonf_layer2_data *l2data,
    uint32_t origin, int64_t value);

EXPORT const struct oonf_layer2_metadata *oonf_layer2_get_neigh_metadata(
    enum oonf_layer2_neighbor_index);
EXPORT const struct oonf_layer2_metadata *oonf_layer2_get_net_metadata(
    enum oonf_layer2_network_index);
EXPORT const char *oonf_layer2_get_network_type(enum oonf_layer2_network_type);
EXPORT struct avl_tree *oonf_layer2_get_network_tree(void);

/**
 * Get a layer-2 interface object from the database
 * @param ifname name of interface
 * @return layer-2 addr object, NULL if not found
 */
static INLINE struct oonf_layer2_net *
oonf_layer2_net_get(const char *ifname) {
  struct oonf_layer2_net *l2net;
  return avl_find_element(oonf_layer2_get_network_tree(), ifname, l2net, _node);
}

/**
 * Get a layer-2 neighbor object from the database
 * @param l2net layer-2 addr object
 * @param addr remote mac address of neighbor
 * @return layer-2 neighbor object, NULL if not found
 */
static INLINE struct oonf_layer2_neigh *
oonf_layer2_neigh_get(const struct oonf_layer2_net *l2net,
    const struct netaddr *addr) {
  struct oonf_layer2_neigh *l2neigh;
  return avl_find_element(&l2net->neighbors, addr, l2neigh, _node);
}

static INLINE struct oonf_layer2_destination *
oonf_layer2_destination_get(const struct oonf_layer2_neigh *l2neigh,
    const struct netaddr *destination) {
  struct oonf_layer2_destination *l2dst;
  return avl_find_element(&l2neigh->destinations, destination, l2dst, _node);
}

/**
 * @param l2data layer-2 data object
 * @return true if object contains a value, false otherwise
 */
static INLINE bool
oonf_layer2_has_value(const struct oonf_layer2_data *l2data) {
  return l2data->_has_value;
}

/**
 * @param l2data layer-2 data object
 * @return value of data object
 */
static INLINE int64_t
oonf_layer2_get_value(const struct oonf_layer2_data *l2data) {
  return l2data->_value;
}

/**
 * @param l2data layer-2 data object
 * @return originator of data value
 */
static INLINE uint32_t
oonf_layer2_get_origin(const struct oonf_layer2_data *l2data) {
  return l2data->_origin;
}

/**
 * Set the value of a layer-2 data object
 * @param l2data layer-2 data object
 * @param origin originator of value
 * @param value new value for data object
 */
static INLINE void
oonf_layer2_set_value(struct oonf_layer2_data *l2data,
    uint32_t origin, int64_t value) {
  l2data->_has_value = true;
  l2data->_value = value;
  l2data->_origin = origin;
}

/**
 * Removes the value of a layer-2 data object
 * @param l2data layer-2 data object
 */
static INLINE void
oonf_layer2_reset_value(struct oonf_layer2_data *l2data) {
  l2data->_has_value = false;
  l2data->_origin = 0;
}

#endif /* OONF_LAYER2_H_ */