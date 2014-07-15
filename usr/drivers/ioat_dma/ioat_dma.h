/*
 * Copyright (c) 2014 ETH Zurich.
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached LICENSE file.
 * If you do not find this file, copies can be found by writing to:
 * ETH Zurich D-INFK, Universitaetsstrasse 6, CH-8092 Zurich. Attn: Systems Group.
 */

#ifndef IOAT_DMA_H
#define IOAT_DMA_H


struct ioat_dma_device;
struct ioat_dma_channel;


#define IOAT_DMA_DCA_ENABLE 1

#define IOAT_DMA_IRQ_TYPE IOAT_DMA_IRQ_DISABLED

struct ioat_dma_ctrl
{
    uint16_t device_num;
    struct ioat_dma_device *devices;
    uint8_t dca_enabled;
    struct ioat_dma_desc_alloc *alloc;
};


#endif /* IOAT_DMA_H */
