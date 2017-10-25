
#include "car.h"

#include "lib/common.h"
#include "task/common.h"



int main() {

  lib::log::memory.on();
  lib::log::lock.on();
  lib::log::task.on();

  auto car0 = strong_ptr<car>{ new car{}, "car"};  

  $task( "test task1", &car0 ) {

    info, "test task!", endl;

    $task( "test task2" ) {

      info, "one more test task!", endl;

      return task::done;
    };

    return task::done;
  };



}




