
#include "lib/common.h"
#include "lib/test.h"

struct test2 : lib::test {
  test2() { info, "test2()", endl; }
  void print() { lib::log::info, "test2::print( ", _oid, " )", lib::log::endl; }
};

int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();
  lib::log::link.on();
  lib::log::event.on();
  lib::log::input.on();
  lib::log::timer.on();

 
  strong_ptr< test2 > p0{ new test2{}, "test" };

  p0->print();

  auto p1 = static_cast< strong_ptr< lib::test >>( p0 );

  p1->print();
}

