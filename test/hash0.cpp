
#include "lib/common.h"

int main() {

  //lib::log::memory.on();

  lib::hash_map< cstr, cstr > map0;

  info, "insert alex1 = ", map0.insert( "name1", "alex1" ), endl;
  info, "insert alex2 = ", map0.insert( "name2", "alex2" ), endl;
  info, "insert alex1 = ", map0.insert( "name1", "alex1" ), endl;

  info, map0.keys(), endl;
  info, map0.values(), endl;

  info, endl;

  lib::hash_map< cstr, int > map1;

  info, "insert alex1 = ", map1.insert( "name1", 1 ), endl;
  info, "insert alex2 = ", map1.insert( "name2", 2 ), endl;
  info, "insert alex1 = ", map1.insert( "name1", 1 ), endl;

  info, map1.keys(), endl;
  info, map1.values(), endl;

  info, endl;

  lib::hash_map< cstr, vector< int > > map3;

  info, "insert alex1 = ", map3.insert( "name1", vector< int >{1,2,3} ), endl;
  info, "insert alex2 = ", map3.insert( "name2", vector< int >{3,4,5} ), endl;


  info, map3.keys(), endl;
  info, map3.values(), endl;

 
}

