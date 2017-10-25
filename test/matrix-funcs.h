#pragma once

#include "lib/macros.h"
#include "lib/types.h"

#include "constant.h"
#include "types.h"
#include "math.h"


namespace lib {

  namespace math {


    TP<TN T>
    constexpr auto rotx( T angle ) {

      return mat< T, 3 >{
        
        vec< T, 3 >{ 1, 0, 0 },
        vec< T, 3 >{ 0, $sin( radians( angle ) ),  $cos( radians( angle ) ) },
        vec< T, 3 >{ 0, $cos( radians( angle ) ), -$sin( radians( angle ) ) }
      };
    }

    TP<TN T>
    constexpr auto roty( T angle ) {

      return mat< T, 3 >{

        vec< T, 3 >{ $cos( radians( angle ) ), 0, -$sin( radians( angle ) ) },
        vec< T, 3 >{ 0, 1, 0 },
        vec< T, 3 >{ $sin( radians( angle ) ), 0,  $cos( radians( angle ) ) }
      };
    }

    TP<TN T>
    constexpr auto rotz( T angle ) {

      return mat< T, 3 >{ 

        vec< T, 3 >{ $cos( radians( angle ) ), -$sin( radians( angle ) ), 0 },
        vec< T, 3 >{ $sin( radians( angle ) ),  $cos( radians( angle ) ), 0 },
        vec< T, 3 >{ 0, 0, 1 }
      };
    }


  }

}


