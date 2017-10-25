
//#include "os/windows.h"
#include "lib/common.h"
#include "loader/common.h"
#include "loader/buffer.h"
//#include "render/common.h"


int main() {

  lib::log::malloc.on();
  lib::log::memory.on();
  lib::log::os.on();
  lib::log::lock.on();
  lib::log::task.on();
  lib::log::link.on();
  lib::log::event.on();
  lib::log::input.on();
  lib::log::timer.on();
  lib::log::render.on();
  lib::log::gfx.on();
  lib::log::loader.on();


  auto vb = loader::buffer::load( "file://box.vb", true );

  info, "loaded buffer = ", vb, endl;
  info, vb->vector(), endl;

}


