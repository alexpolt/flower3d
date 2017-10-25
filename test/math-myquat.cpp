
#include <cstdio>

#include "lib/common.h"
#include "math/common.h"


vec4d hmul_orig( vec4d v, vec4d b ) {

  auto m = mat4d {

    vec4d{  v[0], -v[1], -v[2], -v[3] },
    vec4d{  v[1],  v[0], -v[3],  v[2] },
    vec4d{  v[2],  v[3],  v[0], -v[1] },
    vec4d{  v[3], -v[2],  v[1],  v[0] },
  };

  return m * b;
}

vec4d hmul( vec4d v, vec4d b ) {

  auto m = mat4d {

    vec4d{  v[0], -v[1], -v[2], -v[3] },
    vec4d{  v[1],  v[0],  v[3], -v[2] },
    vec4d{  v[2], -v[3],  v[0],  v[1] },
    vec4d{  v[3],  v[2], -v[1],  v[0] },
  };

  return m * b;
}

vec4d conj( vec4d a ) {

  return vec4d{ a[ 0 ], -a[ 1 ], -a[ 2 ], -a[ 3 ] };
}

vec4d qdiv( vec4d a, vec4d b ) {

  return hmul( a, conj( b ) ) / vec4d{ dot( b, b ) };
}

void test() {

  auto v = $normalize( vec4d{ 0.7, 0.3, 0.25, 1 } );
  auto v0 = v;

  range{ 0, 30 } $do {

   info, v, " = ", length( v ), endl;

   v = hmul( v0, v );

  };

}

int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();

  info, "start program", endl;

  auto a = normalize( vec4d{ 0.7, 0.7, 1, 1 } );
  auto x = normalize( vec4d{ 0.3, 0.3, -1, 0 } );

  auto d0 = qdiv( a, x );

  info, "a ", a, " = ", length( a ), endl, "x ", x, " = ", length( x ), endl;

  info, "(a*x)*a = ", hmul( hmul( a, x), a ), endl;
  info, "a*(x*a) = ", hmul( a, hmul( x, a ) ), endl;

  //return 0;

  info, "a/x = ", d0, " = ", length( d0 ), endl;
  info, "a/x*x = ", hmul( d0, x ), " = ", length( hmul( d0, x ) ), endl, endl;

  test();

  //return 0;

  info, endl, "sqrt of ", a, endl;

  x = vec4d{0.5} * a;

  range{ 0, 15 } $do {

   x = vec4d{ 0.5 } * ( x + qdiv( a, x ) );

   info, x, " = ", length( x ), endl;
  };

  info, endl, "x*x = ", hmul( x, x ), ", length = ", length( hmul( x, x ) ), endl;

}



