/**
 * \file
 * \brief e1000 driver domain.
 *
 * Implements a simple driver domain for e1000
 */
/*
 * Copyright (c) 2016, ETH Zurich.
 * All rights reserved.
 *
 * This file is distributed under the terms in the attached LICENSE file.
 * If you do not find this file, copies can be found by writing to:
 * ETH Zurich D-INFK, Universitaetstrasse 6, CH-8092 Zurich. Attn: Systems Group.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <barrelfish/barrelfish.h>
#include <driverkit/driverkit.h>
#include <barrelfish/nameservice_client.h>

/**
 * Instantiate the driver domain.
 *
 * Connect to Kaluga and wait for eventual ddomain requests.
 */
int main(int argc, char** argv)
{
    iref_t kaluga_iref = 0;
    errval_t err = nameservice_blocking_lookup("ddomain_controller", &kaluga_iref);
    assert(err_is_ok(err));
    err = ddomain_communication_init(kaluga_iref, atoi(argv[argc-1]));
    assert(err_is_ok(err));

    while(1) {
        err = event_dispatch(get_default_waitset());
        if (err_is_fail(err)) {
            USER_PANIC_ERR(err, "error in event_dispatch for messages_wait_and_handle_next hack");
        }
    }

    return 0;
}
