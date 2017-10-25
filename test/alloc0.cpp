

#include "lib/common.h"
#include "lib/alloc-chunk.h"


void test( ) {

}

int main () {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();
  lib::log::link.on();
  lib::log::event.on();
  lib::log::input.on();
  lib::log::timer.on();

  vector< int > v0{ lib::alloc_chunk::create( "test", 256 ) };

  v0 << 1 << 2 << 3;

  info, v0, endl;

  auto v1 = v0;

  v1 << 6 << 7;

  info, v1, endl;

  v1 = v0;

  info, "end", endl, endl;
}



