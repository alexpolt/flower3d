
#include <cstdio>

#include "lib/common.h"
#include "math/common.h"


vec4d qmul( vec4d v, vec4d b ) {

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

  range{ 0, 20 } $do {

   info, v, " = ", norm( v ), endl;

   v = math::qmul( v0, v );

  };

}

int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();

  info, "start program", endl;

  auto a = $normalize( vec4d{ 0.7, 0.7, 1, 1 } );
  auto x = $normalize( vec4d{ 0.3, 0.3, -1, 0 } );


  info, "a ", a, " = ", $norm( a ), endl, "x ", x, " = ", $norm( x ), endl;

  info, "(a*x)*a = ", math::qmul( math::qmul( a, x), a ), endl;
  info, "a*(x*a) = ", math::qmul( a, math::qmul( x, a ) ), endl;

  //return 0;
  auto d0 = math::qdiv( a, x );

  info, endl, "a/x = ", d0, " = ", norm( d0 ), endl;
  info, "a/x*x = ", math::qmul( d0, x ), " = ", norm( math::qmul( d0, x ) ), endl;

  auto d1 = qdiv( a, x );

  info, endl, "a/x = ", d1, " = ", norm( d1 ), endl;
  info, "a/x*x = ", qmul( d1, x ), " = ", norm( qmul( d1, x ) ), endl, endl;


  test();

  //return 0;

  info, endl, "sqrt of ", a, endl;

  x = vec4d{0.5} * a;

  range{ 0, 8 } $do {

   x = vec4d{ 0.5 } * ( x + qdiv( a, x ) );

   info, x, " = ", norm( x ), endl;
  };

  info, endl, "x*x = ", hmul( x, x ), ", length = ", norm( hmul( x, x ) ), endl;

  info, endl, "math::sqrt(a) = ", math::qsqrt( a ), endl;

}



