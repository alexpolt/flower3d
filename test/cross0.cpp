
#include "lib/common.h"
#include "math/common.h"

int main() {

  info, "start", endl;
{
  vec3f v0{1,0,0};
  vec3f v1{0,1,0};

  info, v0, endl, v1, endl, cross( v0, v1 ), endl;
}
{
  vec3f v0{0,1,0};
  vec3f v1{1,0,0};

  info, v0, endl, v1, endl, cross( v0, v1 ), endl;
}

  vec2f v2{1,0};
  vec2f v3{0,1};

  info, v2, endl, v3, endl, cross( v2, v3 ), endl;


}


