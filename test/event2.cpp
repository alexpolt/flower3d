
#include "os/windows.h"
#include "lib/common.h"
#include "os/input.h"
#include "os/vkey-desc.h"
#include "os/action-desc.h"
#include "os/window.h"
#include "os/display-mode.h"
#include "math/common.h"

void draw( owner_ptr< uint >& data, lib::os::window& wnd ) {
  auto w = wnd.width(), h = wnd.height();
  for( int y : range{ 0, h } )
    for( int x : range{ 0, w } ) {
      vec2f v0{ x-w/2, y-h/2 };
      if( sqrt( v0[0]*v0[0]+v0[1]*v0[1] ) < 100 ) 
        *( data.get() + y * w + x ) = 0x00FF'FFFF;
      else
        *( data.get() + y * w + x ) = 0x0000'0000;
    }
}

int main() {

  //lib::log::memory.on();
  lib::log::lock.on();
  lib::log::link.on();
  lib::log::event.on();
  //lib::log::input.on();

  info, "start program", endl;

  lib::os::display_mode dm;
  info, "Display mode w = ", dm.width(), ", h = ", dm.height(), ", bits = ", dm.depth();
  info, ", freq = ", dm.frequency(), endl;

  lib::os::input i;

  bool loop = true;

  auto w = lib::os::window::create( "Flower Engine Test", 800, 600 );

  $event( "key_up", &w ) {
    info, ">>>key_up: key = ", lib::os::get_vkey_desc( event.key ).name, ", action = ", lib::os::get_action_desc( event.action );
    if( event.mod & lib::os::vmod::shift ) info, ", shift";
    if( event.mod & lib::os::vmod::control ) info, ", control";
    if( event.mod & lib::os::vmod::menu ) info, ", menu";
    info, endl;
    if( event.key == lib::os::vkey::escape ) PostQuitMessage( 0 );
    if( event.key == lib::os::vkey::space ) {
      $try {
        owner_ptr< uint > data{ (uint*) operator new( w.width() * w.height() * $size( uint ) ) };
        draw( data, w );
        info, "draw", endl;
        w.set_data( data.get() );
      } $catch( lib::error& e ) { info, e, endl; }
    }
    return false;
  };

  $event( "exit", &loop ) {
    info, ">>>exit", endl;
    loop = false;
    return true;
  };

  $event( "scroll" ) {
    info, ">>>scroll: delta = ", event.y, ", action = ", lib::os::get_action_desc( event.action ), endl;
    return true;
  };

  $event( "mouse_move" ) {
    info, ">>>mouse_move: x = ", event.x, ", y = ", event.y, ", action = ", lib::os::get_action_desc( event.action ), endl;
    return true;
  };

  $event( "mouse_up" ) {
    info, ">>>mouse_up: key = ", lib::os::get_vkey_desc( event.key ).name, ", action = ", lib::os::get_action_desc( event.action ), endl;
    return true;
  };

  //lib::global::event_map<>.dump_events();

  $try {


    while( loop ) {

      i();

      Sleep( 100 );
    }

  } $catch( lib::error& e ) {

    info, e, endl;
  }

}


