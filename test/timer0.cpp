
#include "lib/common.h"
#include "os/common.h"
#include "timer/common.h"

bool loop = true;


int main() {

  //lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();
  lib::log::link.on();
  lib::log::event.on();
  lib::log::input.on();
  lib::log::timer.on();

  os::timer clock;

  $timeout( "test", 1_s ) {

    info, "this is a test", endl;
  };

  $timeout( "test", 1_s ) {

    info, "this is a test", endl;
  };

  $timer( "test", 500_ms ) {

    info, "this is a test", endl;
  };

  $event( "key_up", "main" ) { 

    if( event.key == os::vkey::escape ) loop = false;

    return true;
  };

  auto w = os::window::create( "input", 50, 50 );

  while( loop ) {

    info, "clock ", clock.stop(), endl;

    os::input::process();

    timer::process();

    Sleep( 1000 );
  }

}


