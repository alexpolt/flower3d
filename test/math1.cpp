
#include <cstdio>

#include "lib/common.h"
#include "math/common.h"


int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();

  info, "start program", endl;

  auto c = $cos( math::pi / 40. );
  auto s = $sin( math::pi / 40. );
  auto c2 = $cos( math::pi / 3. );
  auto s2 = $sin( math::pi / 3. );



  vec4d v = $normalize( vec4d{ c2*c,  c2*s,  s2, 0 } );

  auto m = mat4d {

    vec4d{  v[0], -v[1],  v[2], -v[3] },
    vec4d{  v[1],  v[0], -v[3], -v[2] },
    vec4d{  v[2], -v[3], -v[0],  v[1] },
    vec4d{  v[3],  v[2],  v[1],  v[0] },
  };

  range{ 0, 20 } $do {

    v = m*v;

    info, length( v ), endl;

  };

  printf("l = %.15f\n", length( v ));

}


