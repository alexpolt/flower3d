#pragma once

#include "lib/macros.h"
#include "lib/types.h"
#include "lib/value.h"
#include "lib/vector.h"
#include "lib/alloc-default.h"
#include "lib/algo.h"
#include "lib/log.h"
#include "lib/sequence.h"
#include "lib/time.h"
#include "os/timer.h"
#include "types.h"


namespace lib {

  namespace timer {

    namespace global {

      TP<TN T = value< timeout >>
      vector< T > timer_list{ alloc_default::create( "timer_list" ) };

      TP<TN T = value< timeout >>
      vector< T > timeout_list{ alloc_default::create( "timeout_list" ) };

      TP<TN...>
      os::timer clock;
      
    }

    inline void fire_events() {
      
      auto time0 = global::clock<>();

      for( auto& e : global::timer_list<> ) {

        auto time1 = e->get_timeout();
        
        if( time0 > time1 ) {

          log::timer, time0, ", run ", e, ", timeout at ", time1, log::endl;

          e();
        }

        e->set_timeout( time0 + e->get_time() );
      }

      for( auto it = begin( global::timeout_list<> ); it; ) {

        auto& e = *it;
  
        auto time1 = e->get_timeout();
        
        if( time0 >= time1 ) {

          log::timer, time0, ", run once ", e, ", timeout at ", time1, log::endl;

          e();

          it = global::timeout_list<>.erase( it );

          continue;
        }

        ++it;
      }

    }


    inline auto remove( tid_t tid ) {

      auto it = find( global::timer_list<>, [tid]( value< timeout >& timer ){ return tid == timer->get_id(); } );

      if( it ) {

        log::timer, "removed ", *it, log::endl;

        global::timer_list<>.erase( it );

        return true;
      }

      it = find( global::timeout_list<>, [tid]( value< timeout >& timer ){ return tid == timer->get_id(); } );

      if( it ) {

        log::timer, "removed ", *it, log::endl;

        global::timeout_list<>.erase( it );

        return true;
      }

      log::error, $file_line, "timer ", tid, " not found", log::endl;

      return false;
    }


    struct timer_tag {};

    
    TP<TN T> 
    tid_t operator+( timeout_desc desc, T fn ) { 

      auto id = desc.id = lib::global::gen_id< timer_tag >();

      auto timer = value< timeout >::create< timeout_basic< T > >( move( fn ), desc );

      log::timer, "add ", timer, log::endl;

      timer->set_timeout( global::clock<>() + desc.time );

      global::timer_list<>.push_back( move( timer ) );

      return id;
    }

    TP<TN T> 
    tid_t operator-( timeout_desc desc, T fn ) { 

      auto id = desc.id = lib::global::gen_id< timer_tag >();

      auto timer = value< timeout >::create< timeout_basic< T > >( move( fn ), desc );

      log::timer, "add ", timer, log::endl;

      timer->set_timeout( global::clock<>() + desc.time );

      global::timeout_list<>.push_back( move( timer ) );

      return id;
    }


    #define $timer( ... ) \
      lib::timer::timeout_desc{ $args_first( __VA_ARGS__ ),  $args_second( __VA_ARGS__ ) } + \
        [ $args_third( __VA_ARGS__ ) ]() -> void

    #define $timeout( ... ) \
      lib::timer::timeout_desc{ $args_first( __VA_ARGS__ ),  $args_second( __VA_ARGS__ ) } - \
        [ $args_third( __VA_ARGS__ ) ]() -> void


  }

}


