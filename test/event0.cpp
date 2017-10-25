
#include "lib/common.h"
#include "event/common.h"
#include "car.h"

int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::link.on();
  lib::log::event.on();

  info, "start program", endl;

  auto car0 = make_strong< car >(); 
  auto car0_info = car0->get_object( info::tag );

  auto id0 = $event_add( "key_down", car0=car0.lock() ) { info, car0, ">>> hello1 ", (int)event.key, endl; return true; };
  auto id1 = $event_add( "key_down" ) { info,  ">>> hello2 ", (int)event.key, endl; return true; };

  auto& map = lib::global::event_map<>._event_map;

  for( auto i : range{0, map.size()} ) {

    info, "all events: ", map.values()[ i ], endl;
  }

  event::event_data e{ lib::os::vkey::ret };

  event::fire( "key_down", e );

  event::remove( "key_down", id1 );

  auto it = event::create( "key_down" );

  info, "event create: ";
  for( auto& e : *it ) info, e;
  info, endl;
  
  for( auto i : range{0, map.size()} ) {

    info, "all events: ", map.values()[ i ], endl;
  }

}


