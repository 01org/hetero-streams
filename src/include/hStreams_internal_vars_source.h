/*
 * Hetero Streams Library - A streaming library for heterogeneous platforms
 * Copyright (c) 2014 - 2016, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 */

// /////////////////////////////////////////////////////////////////
// Purpose: Contains declarations of global variables used across
//  all hStreams. Those variables are defined in
//  hStreams_internal_vars.cpp which must be included in the compilation.
// /////////////////////////////////////////////////////////////////

#ifndef HSTREAMS_INTERNAL_VARS_SOURCE_H
#define HSTREAMS_INTERNAL_VARS_SOURCE_H

#include "hStreams_types.h"
#include "hStreams_locks.h"
#include "hStreams_internal.h"

#include "hStreams_PhysDomainCollection.h"
#include "hStreams_LogDomainCollection.h"
#include "hStreams_LogStreamCollection.h"
#include "hStreams_LogBufferCollection.h"

#include "hStreams_internal_vars_common.h"
#include "hStreams_internal_types_source.h"

#include <vector>
#include <string>
#include <array>

// Main data structure
extern hStreamHostProcess hstr_proc;

// extern declarations
extern hStreams_RW_Lock phys_domains_lock;
extern hStreams_PhysDomainCollection phys_domains;

extern hStreams_RW_Lock log_domains_lock;
extern hStreams_LogDomainCollection log_domains;

extern hStreams_RW_Lock log_streams_lock;
extern hStreams_LogStreamCollection log_streams;

extern hStreams_RW_Lock log_buffers_lock;
extern hStreams_LogBufferCollection log_buffers;


extern HSTR_ALIGN(64) volatile int64_t huge_page_usage_threshold;

extern const char *host_sink_ld_library_path_env_name;
extern const char *mic_sink_ld_library_path_env_name;

// Generated by the incbin script to a separate .cpp file
extern const uint8_t KNC_startup[];
extern const uint64_t KNC_startup_size;

// Ultimately, all global variables should be places inside this namespace
namespace globals
{

extern HSTR_ALIGN(64) volatile int64_t next_log_dom_id;
extern HSTR_LOG_STR app_init_next_log_str_ID;
extern std::vector<HSTR_LOG_DOM> app_init_log_doms_IDs;

extern std::string interface_version;
extern const std::array<const std::string, 2> supported_interface_versions;

extern hStreams_Atomic_HSTR_STATE hStreamsState;

extern HSTR_OPTIONS options;
extern hStreams_RW_Lock options_lock;

// For the benefit of hStreams_Fini(), for use whenever applicable (i.e. for
// POD types). For more complex objects prefer to use .clear() or similar
namespace initial_values
{
extern const HSTR_LOG_STR app_init_next_log_str_ID;
extern const HSTR_LOG_DOM next_log_dom_id;
extern const HSTR_MKL_INTERFACE mkl_interface;
extern const char* interface_version;
extern hStreams_Atomic_HSTR_STATE hStreamsState;
extern const HSTR_OPTIONS options;
} // namespace initial_values

} // namespace globals

#endif /* HSTREAMS_INTERNAL_VARS_SOURCE_H */