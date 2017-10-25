
#include "lib/common.h"
#include "os/common.h"

int main() {

  //lib::log::memory.on();

  lib::hash_map< string, int > map0;

  auto it = map0.insert( "alex", 5 );

  info, "insert alex - > ", it, endl;

  info, "alex = ", *it, endl;

  info, "values = ", map0.values(), endl;

  info, "erase alex -> ", map0.erase( "alex" ), endl;

  info, "map size = ", map0.size(), ", rehashes = ", map0.rehashes(), endl;

  info, "values = ", map0.values(), endl;

  string key = "name";

  for( auto i : range{ 0, 10 } ) {

    key << i;

    info, "insert ", key.data(), " -> ", map0.insert( key, i ), endl;
    
    key.pop_back();
  }

  info, "values = ", map0.values(), endl;

  info, "map size = ", map0.size(), ", rehashes = ", map0.rehashes(), endl;

  info, "erase name3 -> ", map0.erase( "name3" ), endl;
  info, "erase name7 -> ", map0.erase( "name7" ), endl;

  info, "values = ", map0.values(), endl;
  
  info, "insert name 10 - > ", map0.insert( "name10", 5 ), endl;

  info, "values = ", map0.values(), endl;

  info, map0.keys(), endl;

  info, "erase name10 -> ", map0.erase( map0["name10"] ), endl;

  info, "map size = ", map0.size(), ", rehashes = ", map0.rehashes(), endl;
  
  int idx[]{0,1,2,3,4,5,6,9,10};

  for( auto i : idx ) {

    key << i;

    auto it = map0[ key ];

    info, key.data(), " - > ", ( it ? *it : -1 ), endl;
    
    key.pop_back();
  }


  info, endl;

 
}

