
#include <cstdio>

#include "lib/common.h"
#include "os/common.h"
#include "task/common.h"
#include "math/common.h"


int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();

  info, "start program", endl;

  cstr name = "car0.cpp";

  os::file f0{ name };

  f0.close();

  info, "file ", name, " exists = ", f0.exists(), endl;

  f0.close();

  $try {

  $task("task1", name) {

    os::file f0{ name };

    info, "file size = ", f0.size(), endl;

    vector_b data0 = f0.load();

    data0 << '\0';

    info, endl, data0.data(), endl;

    return task::done;
  };

  } $catch( lib::error& e ) { 

    info, e, endl;

  }

  getchar();

}

