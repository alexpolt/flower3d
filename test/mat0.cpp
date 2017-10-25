
#include "lib/common.h"
#include "os/common.h"
#include "event/common.h"
#include "math/common.h"

int main() {

  mat3f m0{ 1 };

  info, m0, endl;
 
  info, math::rotz( math::pi12f ), endl;

  info, dot( math::rotz( math::pi12f ), m0 ), endl;
  info, dot( math::roty( math::pi12f ), m0 ), endl;
  info, dot( math::rotz( math::pif ), m0 ), endl;

}


