
#include "../lib/common.h"

using vector_t = vector< int >;

result< vector_t > create_vector() {

  vector_t v0{ 1, 2, 3, 4 };

  return libr::failed;
};


int main() {

  auto v0 = create_vector();
 
  if( not v0 ) info, "failed", endl;
  else {

    info, *v0, endl;
  }

}

