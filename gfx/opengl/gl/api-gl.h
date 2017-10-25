#pragma once

#include "lib/macros.h"
#include "lib/assert.h"
#include "lib/types.h"
#include "lib/log.h"
#include "gl.h"
#include "error.h"


namespace lib {

  namespace gfx {

  namespace gl {


    void api_init();


    #include "api-gl-list.h"


    enum class api {

      #define $api_gl_enum( $0 ) $0,
      $api_gl_list( $api_gl_enum )
      size
    };

    constexpr ssize_t api_size = (ssize_t) api::size;


    TP<TN...>
    void* api_ptrs[ api_size ];


    #define $api_gl_name( $0 ) $str( $paste( gl, $0 ) ), 

    TP<TN...>
    cstr api_names[] { $api_gl_list( $api_gl_name ) };


    TP<TN T> struct map { using type = T; };
    TP<> struct map< int > { using type = uint; };
    TP<TN T> using map_t = typename map< T >::type;


    TP<TN... TT, TN... UU, TN R0, TN R1>
    void check_args( R0 (APIENTRY *)(TT...), R1(UU...) ) {
        
      static_assert( all_v< is_same_v< map_t< TT >, map_t< UU > >... >, "invalid arguments to a gl function"  );
    }


    #define $api_gl_thunk( $0 ) \
    TP<TN... TT, TN R = decltype( ::$paste( gl, $0 )( declval< TT >()...) ) >         \
    R $0( TT... args ) {                                                              \
      using fn_orig_ptr = decltype( ::$paste( gl, $0 ) )*;                            \
      using fn_ptr = R (*)( TT... );                                                  \
      check_args( fn_orig_ptr{}, fn_ptr{} );                                          \
      $assert( api_ptrs<>[ (ssize_t) api::$0 ], "opengl function wasn't loaded" );    \
      return fn_orig_ptr( api_ptrs<>[ (ssize_t) api::$0 ] )( args... );               \
    }


    $api_gl_list( $api_gl_thunk )


    inline void api_init() { 

      static decltype( $loadOpenglLib() ) handle{};

      log::gfx, "load gl entry points", log::endl;

      ssize_t index = 0;

      for( auto name : api_names<> ) {

        log::gfx, "load ", name;

        void* ptr = (void*) $glGetProcAddress( name );

        ssize_t n = (ssize_t) ptr;

        if( n == 0 or n == 1 or 
            n == 2 or n == 3 or n == -1 ) {
          
          if( not handle ) handle = $loadOpenglLib();

          if( not handle ) $throw $error_api( name );

          ptr = (void*) $getProcAddress( handle, name );

          if( not ptr ) $throw $error_api( name );
        }

        log::gfx, " = ", ptr, log::endl;

        api_ptrs<>[ index++ ] = ptr;
      }

      log::gfx, "loading finished", log::endl;
    }


  }
  }
}


