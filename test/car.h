#pragma once

#include "lib/common.h"


struct info : component {

  $interface( info );
};

TP<TN>
struct car_info;

struct car : object {

  $object( car, car_info< car > );

  car() { lib::log::info, "car ", (void*)this, endl; }

  ~car() { lib::log::info, "~car ", (void*)this, endl; }
};


TP<TN T0>
struct car_info : info {

  $component( car_info );
  //$component_template( car_info );

  car_info( weak_ptr< car > owner ) : _owner{ move( owner ) } { 
    
    lib::log::info, "car_info ", _owner, endl; 
  }

  ~car_info() { lib::log::info, "~car_info ", _owner, endl; }

  weak_ptr< object > get_owner() override { return _owner.lock(); }

  weak_ptr< car > _owner;
};


