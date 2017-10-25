#pragma once

#include <cstdint>

#include "lib/macros.h"
#include "lib/types.h"
#include "lib/assert.h"
#include "lib/vector.h"
#include "lib/hash-map.h"
#include "lib/algo.h"
#include "lib/log.h"
#include "lib/strong-ptr.h"
#include "lib/value.h"
#include "lib/alloc-default.h"


namespace lib {


  TP<TN T = object_wp>
  struct linker {

    using link_map = hash_map< void*, vector< T > >;
    using allocator = value< allocator >;

    static allocator create_alloc() { return alloc_default::create( "link_map" ); }

    linker() { }

    ~linker() {
      
      ssize_t c = 0;

      for( auto& e : _child_map ) c += e.size();

      if( c )
        
        log::warn, $file_line, "child map is not empty", log::endl;
    }
    
    void link( object_wp a, object_wp b, bool ignore_duplicates ) {

      log::link, "link between ", a, " and ", b, " )", log::endl;

      auto b_ptr = b.get();

      auto r0 = _link( _child_map, a.get(), move( b ), ignore_duplicates );

      auto r1 = _link( _parent_map, b_ptr, move( a ), ignore_duplicates );

      if( r0 != r1 )

        log::error, $file_line, "links are not symmetrical", log::endl;
    }

    void unlink( void* a, object_wp const& b, bool ignore ) {

      log::link, "unlink between ", a, " and ", b, " )", log::endl;

      auto r0 = _unlink( _child_map, a, b.get(), ignore );

      auto r1 = _unlink( _parent_map, b.get(), a, ignore );

      if( r0 != r1 )

        log::error, $file_line, "links between ", a, " and ", b, " are not symmetrical", log::endl;
    }

    vector< object_wp > const& get_children( void const* obj ) {

      auto it = _child_map[ (void*) obj ];

      if( not it ) it = _child_map.insert( (void*) obj, vector< object_wp >{} );

      return *it;
    }

    vector< object_wp > const& get_parents( void const* obj ) {

      auto it = _parent_map[ (void*) obj ];

      if( not it ) it = _parent_map.insert( (void*) obj, vector< object_wp >{} );

      return *it;
    }

    bool _link( link_map& map, void* a, object_wp b, bool ignore_duplicates ) {

      auto it = map[ a ];

      if( not it ) it = map.insert( a, vector< object_wp >{} );

      if( find( *it, b ) ) {

        if( not ignore_duplicates ) {

          log::error, $file_line, a, " and ", b," are already linked", log::endl;

          return false;
        }
      }

      it->push_back( move( b ) );

      return true;
    }

    bool _unlink( link_map& map, void* a, void* b, bool ignore ) {

      auto it = map[ a ];

      if( not it ) {

        if( not ignore )

          log::error, $file_line, a, " and ", b," are not linked", log::endl;

        return false;
      }

      auto it_child = find( *it, ( object* ) b );

      if( not it_child ) {

        if( not ignore )

          log::error, $file_line, a, " and ", b," are not linked", log::endl;

        return false;
      }

      it->erase( it_child );

      return true;
    }


    link_map _child_map{ create_alloc() };
    link_map _parent_map{ _child_map.get_allocator().get_copy() };
  };


}
  



