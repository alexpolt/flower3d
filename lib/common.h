#pragma once

#include "config.h"
#include "macros.h"
#include "assert.h"
#include "types.h"
#include "range.h"
#include "buffer.h"
#include "error.h"
#include "memory.h"
#include "log.h"
#include "algo.h"
#include "scope-guard.h"
#include "vector.h"
#include "string.h"
#include "hash-map.h"
#include "queue.h"
#include "value.h"
#include "ret.h"
#include "optional.h"
#include "ptr.h"
#include "owner-ptr.h"
#include "strong-ptr.h"
#include "allocator.h"
#include "handle.h"
#include "time.h"


using lib::value;
using lib::range;
using lib::move;
using lib::forward;
using lib::log::info;
using lib::log::endl;
using lib::vector;
using lib::vector_b;
using lib::vector_i;
using lib::vector_f;
using lib::vector_d;
using lib::string;
using lib::hash_map;
using lib::ret_t;
using lib::optional;
using lib::owner_ptr;
using lib::make_owner;
using lib::weak_ptr;
using lib::strong_ptr;
using lib::make_strong;
using lib::handle;
using lib::operator ""_t;


