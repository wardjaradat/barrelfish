/**
 * \file
 * \brief
 */

/*
 * Copyright (c) 2010, ETH Zurich.
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached LICENSE file.
 * If you do not find this file, copies can be found by writing to:
 * ETH Zurich D-INFK, Universitaetstrasse 6, CH-8092 Zurich. Attn: Systems Group.
 */

#ifndef OFFSETS_ARCH_H
#define OFFSETS_ARCH_H

#include <target/k1om/offsets_target.h>

#define MEMORY_OFFSET             K1OM_MEMORY_OFFSET

#define PADDR_SPACE_SIZE          K1OM_PADDR_SPACE_SIZE
#define PADDR_SPACE_LIMIT         K1OM_PADDR_SPACE_LIMIT

#define REAL_MODE_LINEAR_OFFSET   K1OM_REAL_MODE_LINEAR_OFFSET
#define REAL_MODE_SEGMENT         K1OM_REAL_MODE_SEGMENT
#define REAL_MODE_OFFSET          K1OM_REAL_MODE_OFFSET

#define REAL_MODE_SEGMENT_TO_REAL_MODE_PAGE(seg)      K1OM_REAL_MODE_SEGMENT_TO_REAL_MODE_PAGE(seg)
#define REAL_MODE_ADDR_TO_REAL_MODE_VECTOR(seg,off)   K1OM_REAL_MODE_ADDR_TO_REAL_MODE_VECTOR(seg,off)

#ifndef __ASSEMBLER__

/**
 * Takes absolute physical address addr and returns corresponding
 * "physical memory address space" address.
 *
 * \param addr  Absolute physical address
 *
 * \return Corresponding "physical memory address space" address.
 */
static inline lvaddr_t local_phys_to_mem(lpaddr_t addr)
{
    assert(addr < K1OM_PADDR_SPACE_LIMIT);
    return (lvaddr_t)(addr + (lvaddr_t)K1OM_MEMORY_OFFSET);
}

/**
 * Checks whether absolute local physical address `addr` is valid.
 * \param addr Absolute local physical address
 * \return True iff addr is a valid local physical address
 */
static inline bool local_phys_is_valid(lpaddr_t addr)
{
    return addr < K1OM_PADDR_SPACE_LIMIT;
}
/**
 * Takes "physical memory address space" address and returns
 * corresponding physical address.
 *
 * \param addr  Absolute physical address
 *
 * \return Corresponding "physical memory address space" address.
 */
static inline lpaddr_t mem_to_local_phys(lvaddr_t addr)
{
    assert(addr >= K1OM_MEMORY_OFFSET);
    return (lpaddr_t)(addr - (lpaddr_t)K1OM_MEMORY_OFFSET);
}

static inline lpaddr_t gen_phys_to_local_phys(genpaddr_t addr)
{
    return (lpaddr_t)addr;
}

static inline genpaddr_t local_phys_to_gen_phys(lpaddr_t addr)
{
    return (genpaddr_t)addr;
}

/**
 * Symbol: Start of kernel image. This symbol points to the start
 * address of the kernel image.
 */
extern char _start_kernel;

/**
 * Symbol: End of kernel image. This symbol points to the end address
 * of the kernel image.
 */
extern char _end_kernel;

extern char _end_kernel_text;

/**
 * The size of the whole kernel image.
 */
#define SIZE_KERNEL_IMAGE       \
    (size_t)(&_end_kernel - &_start_kernel)

#endif // __ASSEMBLER__

#endif // OFFSETS_ARCH_H
