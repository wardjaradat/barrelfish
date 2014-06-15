/*
 * Copyright (c) 2014 ETH Zurich.
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached LICENSE file.
 * If you do not find this file, copies can be found by writing to:
 * ETH Zurich D-INFK, Universitaetsstrasse 6, CH-8092 Zurich. Attn: Systems Group.
 */

#ifndef VIRTIO_HOST_CHANNEL_H
#define VIRTIO_HOST_CHANNEL_H


errval_t virtio_host_flounder_init(char *iface,
                                   struct virtio_host_cb *callbacks);


errval_t virtio_host_xeon_phi_init(void);


#endif // VIRTIO_GUEST_CHANNEL_H
