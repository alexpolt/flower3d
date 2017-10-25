#pragma once

#include "config.h"

#define $paste_( $0, $1 ) $0##$1
#define $paste( $0, $1 ) $paste_( $0, $1 )

#define $str_( $0 ) #$0
#define $str( $0 ) $str_( $0 )

#define $empty_( ... )
#define $empty( ... ) $empty_( __VA_ARGS__ )

//skip 0
$empty( __COUNTER__ )

#define $file_line __FILE__ ":" $str( __LINE__ )

#define $escape( $0 ) asm volatile( "" : : "g" ((void*)$0) : "memory" )
#define $clobber( $0 ) asm volatile( "" ::: "memory" )

#define $this (*this)

#define $size( $0 ) int( sizeof( $0 ) )

#ifdef $CONFIG_NO_EXCEPT

  #define $throw $assert( false, "Unexpected exception!" ), (void)
  #define $try
  #define $catch( $0 ) for( lib::error e{}; false; )

#else

  #define $try try
  #define $catch( $0 ) catch( $0 )
  #define $throw throw

#endif

#define TN typename
#define TP template
#define TP1 template
#define TP2 template

TP<TN T0, unsigned N0, unsigned N1, unsigned N2>
auto array_length_function( T0( &)[ N0 ][ N1 ][ N2 ] ) -> char( &)[ N0 * N1 * N2 ];

TP<TN T0, unsigned N0, unsigned N1>
auto array_length_function( T0( &)[ N0 ][ N1 ] ) -> char( &)[ N0 * N1 ];

TP<TN T0, unsigned N0> 
auto array_length_function( T0( &)[ N0 ] ) -> char( &)[ N0 ];

#define $array_size( $0 ) $size( array_length_function( $0 ) )

#define $var $paste( var, __COUNTER__ )

#define $apply( $0, ... ) $0( __VA_ARGS__ )

#define $args_size__( $6, $5, $4, $3, $2, $1, $0, N, ... ) N
#define $args_size_( ... ) $args_size__( __VA_ARGS__, 6, 5, 4, 3, 2, 1, 0 )
#define $args_size( ... ) $args_size_( 0, ##__VA_ARGS__ )

#define $args_first( $0, ... ) $0
#define $args_second_1( $0 )
#define $args_second_2( $0, $1 ) $1
#define $args_second_3( $0, $1, $2 ) $1
#define $args_second( ... ) $apply( $paste( $args_second_, $args_size( __VA_ARGS__ ) ), __VA_ARGS__ )
#define $args_third_1( $0 )
#define $args_third_2( $0, $1 )
#define $args_third_3( $0, $1, $2 ) $2
#define $args_third( ... ) $apply( $paste( $args_third_, $args_size( __VA_ARGS__ ) ), __VA_ARGS__ )


#define $apply1( $macro, $1 ) $macro( $1 );
#define $apply2( $macro, $1, $2 ) $apply1( $macro, $1 ) $apply1( $macro, $2 )
#define $apply3( $macro, $1, $2, $3 ) $apply2( $macro, $1, $2 ) $apply1( $macro, $3 )

#define $applyall( $macro, ... ) $apply( $paste( $apply, $args_size( __VA_ARGS__ ) ), $macro, __VA_ARGS__ )


