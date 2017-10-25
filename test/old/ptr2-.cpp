
#include "../lib/common.h"
#include "../lib/shared-ptr.h"
#include "../lib/test.h"

using namespace lib;


vector< shared_ptr< test > > create() {

  vector< shared_ptr< test > > v;

  info, "start adding", endl;

  range{ 0, 2 } $do {

    v << shared_ptr< test >{ new test{} };
  };

  return v;
}


