
#include "lib/common.h"
#include "lib/hash.h"


struct test {

  int to_hash( int seed ) const {

    info, "to hash ", seed, endl;

    return 10;
  }
};

int main() {


  info, "hash = ", lib::hash32<>::get_hash( test{} ), endl;

}


