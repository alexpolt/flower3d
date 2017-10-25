#include <cstdio>

#include "lib/common.h"
#include "loader/common.h"
#include "task/common.h"


int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();

  info, "start program", endl;

  $try {

    auto data0 = loader::load( "file://map0.txt" );

    data0->back() = '\0';

    info, data0->data();

    getchar();

  } $catch( lib::error& e ) { 

    info, e, endl;

  }

}

