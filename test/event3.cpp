
#include "os/windows.h"
#include "lib/common.h"
#include "os/input.h"
#include "os/vkey-desc.h"
#include "os/action-desc.h"
#include "os/window.h"


int main() {

  //lib::log::memory.on();
  lib::log::lock.on();
  lib::log::link.on();
  lib::log::event.on();
  //lib::log::input.on();

  info, "start program", endl;

  lib::os::input i;

  bool loop = true;

  $event( "window" ) {
    info, ">>>window: action = ", lib::os::get_action_desc( event.action ), ", x = ", event.x, ", y = ", event.y, endl;
    if( event.action == lib::os::action::paint ) ValidateRect( (*(MSG*)event.data).hwnd, nullptr );
    return true;
  };

  $event( "key_up" ) {
    info, ">>>key_up: key = ", lib::os::get_vkey_desc( event.key ).name, ", action = ", lib::os::get_action_desc( event.action );
    if( event.mod & lib::os::vmod::shift ) info, ", shift";
    if( event.mod & lib::os::vmod::control ) info, ", control";
    if( event.mod & lib::os::vmod::menu ) info, ", menu";
    info, endl;
    if( event.key == lib::os::vkey::escape ) PostQuitMessage( 0 );
    return true;
  };

  $event( "exit", &loop ) {
    info, ">>>exit", endl;
    loop = false;
    return true;
  };

  $event( "scroll_up" ) {
    info, ">>>scroll_up: delta = ", event.y, ", action = ", lib::os::get_action_desc( event.action ), endl;
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

  auto r = CreateWindowA( "STATIC", "Test", WS_OVERLAPPED | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 320, 240, 0,0 , GetModuleHandle(0), 0 );

  info, "create window = ", lib::to_string("%#0X",r), endl;

  while( loop ) {

    i();

    Sleep( 100 );
  }

}


