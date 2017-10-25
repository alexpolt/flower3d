#pragma once

#include "lib/macros.h"
#include "lib/types.h"
#include "vkey.h"
#include "action.h"


namespace lib {

  namespace os {


    inline action input_map( vkey key ) {

      static vkey vkeys[] { 

        vkey::a, vkey::s, vkey::w, vkey::d, vkey::space, vkey::shift, 
        vkey::lbutton, vkey::rbutton, 
        vkey::escape, vkey::scroll, vkey::control, vkey::menu
      };

      static action actions[] { 

        action::left, action::down, action::up, action::right, action::jump, action::crouch,
        action::attack1, action::attack2, 
        action::cancel, action::scroll, action::cursor, action::cursor_on
      };

      for( auto i : range{ 0, $array_size( vkeys ) } )

        if( vkeys[ i ] == key ) return actions[ i ];

      return action::null;
    }

  }
}


