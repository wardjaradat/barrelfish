/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached LICENSE file.
 * If you do not find this file, copies can be found by writing to:
 * ETH Zurich D-INFK, Haldeneggsteig 4, CH-8092 Zurich. Attn: Systems Group.
 */

#ifndef KERNEL_ARCH_ARM_IRQ_H
#define KERNEL_ARCH_ARM_IRQ_H

/*
 * Interrupt controller (Cortex-A9 MPU INTC) with up to 128 interrupt requests
 */
#define NUM_INTR                (128+32)

/// Size of hardware IRQ dispatch table == #NIDT - #NEXCEPTIONS exceptions
#define NDISPATCH               (NUM_INTR)

struct capability;
struct idc_recv_msg;
//struct sysret irq_table_set(struct capability *to, struct idc_recv_msg *msg);
//struct sysret irq_table_delete(struct capability *to, struct idc_recv_msg *msg);
errval_t irq_table_set(unsigned int nidt, capaddr_t endpoint);
errval_t irq_table_delete(unsigned int nidt);
struct kcb;
errval_t irq_table_notify_domains(struct kcb *kcb);
void send_user_interrupt(int irq);

errval_t platform_init_bsp_irqs(void);
errval_t platform_init_app_irqs(void);
uint32_t platform_get_active_irq(void);
void     platform_acknowledge_irq(uint32_t irq);
void     platform_enable_interrupt(uint32_t int_id, uint8_t cpu_targets, uint16_t prio,
                              bool edge_triggered, bool one_to_n);

#endif // KERNEL_ARCH_ARM_IRQ_H
