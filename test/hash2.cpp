
#include <algorithm>

#include "lib/common.h"
#include "os/common.h"
#include "lib/alloc-chunk.h"

int main() {

  //lib::log::lock.on();
  //lib::log::memory.on();

  //cstr filename = "../data/hitch3.txt";
  cstr filename = "passwords.txt";

  os::file f0{ filename };

  f0.open();

  info, "size of ", filename, " = ", f0.size();
  info, ", is eof = ", f0.eof(), endl;

  int counter{}, wc{};

  hash_map< string, int > map0{ 16 };

  info, "hash map max size = ", map0.size_max(), endl;

  string s{ 32, lib::alloc_default::create( "hitch" ) };
  //string s{ 32, lib::alloc_chunk::create( "hitch", 131072 ) };

  while( true ) {

    s.clear();

    f0.get_line( s );


    auto l = s;

    if( not l.size() )  break;
    
    ++counter;

    l.pop_back();
    l.back() = '\0';
  
    //info, l, endl;

    auto it = map0[ l ];

    if( it ) {

      (*it)++;

    } else {

      map0.insert( move( l ), 1 );
      //info, "insert -> ", r, endl;
    }

    //if( counter == 500000 ) break;
  }

  //for( auto& e : map0._hash_table ) info, e.get_hash(), " (", e.get_refcnt(), "), ";
/*
  auto& k = map0.keys();
  auto& v = map0.values();

  struct pair {
    int index;
    int value;
  };
  vector<pair> v2{ v.size() };
  for( auto i : range{0, v.size()} ) {

    v2 << pair{ i, v[i] };

    wc += v[i];
  }

  std::sort( begin( v2 ), end( v2 ), [](pair& left, pair& right ){ return left.value < right.value; });

  for( auto i : range{ v2.size()-10, v2.size() } ) {

    info, k[ v2[i].index ].data(), " = ", v2[ i ].value, endl;
  }
*/  
  info, "total lines = ", counter, ", total increments = ", wc, endl;

  info, endl, "hash table size = ", map0._hash_table.size(), ", keys = ", map0.keys().size(), endl;
  info, "rehash = ", map0.rehashes(), endl;

  //info, map0.keys(), endl, endl;
  //info, map0.values(), endl;

  //getchar();
}


