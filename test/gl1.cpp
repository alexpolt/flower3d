
#include "os/common.h"
#include "lib/common.h"
#include "render/common.h"
#include "gfx/common.h"
#include "loader/common.h"
#include "loader/buffer.h"

const int w = 640, h = 640;

int main() {

  //lib::log::malloc.on();
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


  auto win0 = os::window::create( "Test window", w, h );

  win0.show();
  
  $event( "key_up", "main" ) {

    if( event.action == os::action::cancel ) PostQuitMessage( 0 );

    if( event.key == os::vkey::c ) {

      render::messages::clear msg{};
      msg.color = render::color{ 255, 0, 128, 0 };
      render::push( move( msg ) );
    }

    if( event.key == os::vkey::v ) {

      auto vb = loader::buffer::load( "file://box.vb", true );
      info, "loaded buffer = ", vb, endl;
      info, vb->vector(), endl;

      render::messages::vbuffer msg{};
      msg.vbuffer = move( vb );
      render::push( move( msg ) );
    }

    return true;
  };

  //render::camera cam0{ vec3f{ 0, 0, -5 }};
  //render::camera_control cam0_control{ cam0, 0.25_rad, 0.05 };

  os::timer t;

  gfx::context ctx{ win0.handle() };

  ctx.init();

  while( true ) {

    if( not os::input::fire_events() ) break;

    //cam0_control();

    //timer::fire_events();

    ctx();

    os::sleep( 0.001_t );

  }


}


