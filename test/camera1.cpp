
#include "os/windows.h"
#include "lib/common.h"
#include "os/common.h"
#include "render/common.h"
#include "math/common.h"

const int w = 800, h = 800;

uint data[ h ][ w ];

void data_clear() {

  for( auto y : range{ 0, h } )
  for( auto x : range{ 0, w } ) {
    data[ y ][ x ] = 0;
  }
}

void data_draw( render::camera& cam ) {

  int r = 20;

  for( auto zz : range{ 0, 2 } )
  for( auto yy : range{ 0, r } )
  for( auto xx : range{ 0, r } ) {

    vec3f v;
    
    if( zz == 0 ) {
      v[0] = 2.f * float( xx ) / r - 1.f;
      v[1] = 2.f * float( yy ) / r - 1.f;
      v[2] = 0;
    } else {
      v[0] = 2.f * float( xx ) / r - 1.f;
      v[1] = 0;
      v[2] = 2.f * float( yy ) / r;
     }
    
    uchar red = 128 + v[0] * 127;
    uchar green = 128 + v[1] * 127;
    uchar blue = 128 + v[2] * 127;


    v = cam.rotation()*v  - cam.position();

    if( v[2] < 1 ) continue;

    v = v  / v[2];

    int uu = ( v[0] + 1.f ) / 2.f * w;
    int vv = ( v[1] + 1.f ) / 2.f * h;

    uu = lib::max( 0, lib::min( uu, w - 1 ) );
    vv = lib::max( 0, lib::min( vv, h - 1 ) );

    auto uu2 = lib::max( 0, lib::min( uu+1, w - 1 ) );
    auto vv2 = lib::max( 0, lib::min( vv+1, h - 1 ) );

    data[ h - 1 - vv ][ uu ] = ( red << 16 ) | ( green << 8 ) | ( blue );
    data[ h - 1 - vv ][ uu2 ] = ( red << 16 ) | ( green << 8 ) | ( blue );
    data[ h - 1 - vv2 ][ uu ] = ( red << 16 ) | ( green << 8 ) | ( blue );
  }
}

int main() {

  //lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();
  lib::log::link.on();
  //lib::log::event.on();
  //lib::log::input.on();
  lib::log::timer.on();


  auto win0 = os::window::create( "Test window", w, h );
  
  os::cursor_center();

  $event( "key_up", "main", &win0 ) {

    if( event.action == os::action::cancel ) win0.close();

    return true;
  };

  render::camera cam0{ vec3f{ 0, 0, -5 }};
  render::camera_control cam0_control{ cam0, 0.25_rad, 0.0125 };

  info, cam0, endl;

  while( true ) {

    if( not os::input::process() ) break;

    cam0_control();

    data_clear();

    data_draw( cam0 );

    win0.set_data( (uint*) data );

    Sleep( 1 );

    //info, cam0.rotation(), endl;
  }

}


