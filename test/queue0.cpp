
#include "lib/common.h"
#include "lib/queue.h"


int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();
  lib::log::link.on();
  lib::log::event.on();
  lib::log::input.on();
  lib::log::timer.on();


  lib::queue< int, 8 > q{};

  info, q.size(), "; ", q, endl;

  for( auto i : range{ 1, 5 } ) q << i;

  info, q.size(), "; ", q, endl;

  int a = 0;

  q >> a;

  info, q.size(), ", ", a, "; ", q, endl;

  int b = q.pop();
  int c = q.pop();

  info, q.size(), ", ", b, ", ", c, "; ", q, endl;

  for( auto it = begin( q ); it; it++ ) info, "q = ", *it, " ";
}


