
#include "../lib/common.h"
#include "../lib/shared-ptr.h"
#include "../lib/test.h"

using namespace lib;

vector< shared_ptr< test > > create();

int main() {

  log::memory.on();

  info, "test: ptr, ", endl;

//  shared_ptr< test > s0{ new test{} };
//  shared_ptr< test > s1;
//  s1 = move( s0 );
//  s1 = s0.lock();

  auto v0 = create();

  info, "v0 = ", v0, endl;

  vector< shared_ptr< test > > v1;

  v1 << move( v0 );


  info, "done",endl;
}


