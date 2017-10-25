
#include "lib/common.h"
#include "render/common.h"

struct a {};
struct b : a {};

int main() {

  lib::log::memory.on();
  lib::log::malloc.on();
  lib::log::lock.on();
  lib::log::task.on();
  lib::log::link.on();
  lib::log::event.on();
  lib::log::input.on();
  lib::log::timer.on();
  lib::log::render.on();


  auto msg = render::create_message< render::messages::mesh >();

  render::push( move( msg ) );

  info, "render queue: ", render::global::render_queue<>, endl;

  info, "pop", endl;

  render::pop( );

  info, "render free queue: ";
  
  for( auto e : render::global::messages_ptrs[ msg.type() ] ) info, (void*) e, ", ";

  info, endl;

  info, "create from free", endl;

  msg = render::create_message< render::messages::shader >();

  render::push( move( msg ) );

  info, "render queue: ", render::global::render_queue<>, endl;

  info, "render free queue: ";
  
  for( auto e : render::global::messages_ptrs[ msg.type() ] ) info, (void*) e, ", ";

  info, endl;


}


