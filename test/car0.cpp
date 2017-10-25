
#include "lib/common.h"


struct info_t : component {

  $interface( info_t );
};

TP<TN>
struct car_info;

struct car : object {

  $object( car, car_info< car > );

  car() { info, "car ", (void*)this, endl; }
  ~car() { info, "~car ", (void*)this, endl; }
};

struct bike : object {

  $object( bike, car_info< bike > );

  bike() { info, "bike ", (void*)this, endl; }
  ~bike() { info, "~bike ", (void*)this, endl; }
};

TP<TN T0>
struct car_info : info_t {

  $component_template( car_info );

  //car_info( weak_ptr< car > owner ) : _owner{ move( owner ) } { info, "car_info ", _owner, endl; }
  //~car_info() { info, "~car_info ", _owner, endl; }

  //weak_ptr< object > get_owner() override { return _owner.lock(); }

  //weak_ptr< car > _owner;
};

int main() {

  lib::log::memory.on();
  lib::log::lock.on();

  shared_ptr< car > car0 { new car{} };
  auto info0 = car0->get_object( info_t::tag );
  info, info0, endl;
  auto obj0 = info0->get_owner();
  info, *car0, obj0, endl;

  vector< shared_ptr< object > > v;
  v << make_shared< car >();
  v << make_shared< bike >();

  info, "v.size = ", v.size(), v[0], endl;

  for( auto& e : v ) info, e, endl;

  //info, "locker: ", owner0.get_locker()._lock_map, endl;

}


