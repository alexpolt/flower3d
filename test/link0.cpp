
#include "lib/common.h"
#include "car.h"

int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::link.on();

  info, "start program", endl;

  auto car0 = strong_ptr< car >( new car{}, "car0" );
  auto car1 = strong_ptr< car >( new car{}, "car1" );

  car0->child_add( car1 );
  car0->child_add( car1 );

  for( auto& e : car0->get_children() ) info, ">>> ", e->to_string(), endl;

  car0->child_remove( car1 );

  for( auto& e : car0->get_children() ) info, ">>> ", e->to_string(), endl;

  info, "start program", endl;


}


