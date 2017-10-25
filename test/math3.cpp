
#include "math/common.h"
#include "lib/common.h"


int main() {


  mat3f v0{ vec3f{1}, vec3f{1,2} };
  info, "v0: \n", v0, endl;

  mat3f v1{ 4, 5, 6, 7, 8 };
  info, "v1: \n", v1, endl;

  info, "v0 = v1: \n", v0 = v1, endl;
}


