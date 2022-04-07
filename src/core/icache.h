#ifndef ICACHE_H
#define ICACHE_H

#include "wishbone_common.h"

declare icache {
    func_in reset();
    input req_cache_addr[32];
    func_in req_cache_read(req_cache_addr);
    output rsp_cache_data[64];
    func_out rsp_cache_hit(rsp_cache_data);
    func_out rsp_cache_miss();

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
    WISHBONE_MASTER_ACCESS_OUT_PORTS(32, 64, 8)
}

#endif
