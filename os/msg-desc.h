#pragma once

#include "windows.h"


namespace lib {

  namespace os {

  
    struct msg_desc_t {

      DWORD message;

      cstr desc;
    };
    
    #define DEFINE_MESSAGE(wm){ wm, #wm }
  
    constexpr msg_desc_t msg_desc[] {
      
      DEFINE_MESSAGE(WM_CREATE),
      DEFINE_MESSAGE(WM_DESTROY),
      DEFINE_MESSAGE(WM_MOVE),
      DEFINE_MESSAGE(WM_SIZE),
      DEFINE_MESSAGE(WM_ACTIVATE),
      DEFINE_MESSAGE(WM_SETFOCUS),
      DEFINE_MESSAGE(WM_KILLFOCUS),
      DEFINE_MESSAGE(WM_ENABLE),
      DEFINE_MESSAGE(WM_SETREDRAW),
      DEFINE_MESSAGE(WM_SETTEXT),
      DEFINE_MESSAGE(WM_GETTEXT),
      DEFINE_MESSAGE(WM_GETTEXTLENGTH),
      DEFINE_MESSAGE(WM_PAINT),
      DEFINE_MESSAGE(WM_CLOSE),
      DEFINE_MESSAGE(WM_QUERYENDSESSION),
      DEFINE_MESSAGE(WM_QUIT),
      DEFINE_MESSAGE(WM_QUERYOPEN),
      DEFINE_MESSAGE(WM_ERASEBKGND),
      DEFINE_MESSAGE(WM_SYSCOLORCHANGE),
      DEFINE_MESSAGE(WM_ENDSESSION),
      DEFINE_MESSAGE(WM_SHOWWINDOW),
      DEFINE_MESSAGE(WM_CTLCOLORMSGBOX),
      DEFINE_MESSAGE(WM_CTLCOLOREDIT),
      DEFINE_MESSAGE(WM_CTLCOLORLISTBOX),
      DEFINE_MESSAGE(WM_CTLCOLORBTN),
      DEFINE_MESSAGE(WM_CTLCOLORDLG),
      DEFINE_MESSAGE(WM_CTLCOLORSCROLLBAR),
      DEFINE_MESSAGE(WM_CTLCOLORSTATIC),
      DEFINE_MESSAGE(WM_WININICHANGE),
      DEFINE_MESSAGE(WM_SETTINGCHANGE),
      DEFINE_MESSAGE(WM_DEVMODECHANGE),
      DEFINE_MESSAGE(WM_ACTIVATEAPP),
      DEFINE_MESSAGE(WM_FONTCHANGE),
      DEFINE_MESSAGE(WM_TIMECHANGE),
      DEFINE_MESSAGE(WM_CANCELMODE),
      DEFINE_MESSAGE(WM_SETCURSOR),
      DEFINE_MESSAGE(WM_MOUSEACTIVATE),
      DEFINE_MESSAGE(WM_CHILDACTIVATE),
      DEFINE_MESSAGE(WM_QUEUESYNC),
      DEFINE_MESSAGE(WM_GETMINMAXINFO),
      DEFINE_MESSAGE(WM_ICONERASEBKGND),
      DEFINE_MESSAGE(WM_NEXTDLGCTL),
      DEFINE_MESSAGE(WM_SPOOLERSTATUS),
      DEFINE_MESSAGE(WM_DRAWITEM),
      DEFINE_MESSAGE(WM_MEASUREITEM),
      DEFINE_MESSAGE(WM_DELETEITEM),
      DEFINE_MESSAGE(WM_VKEYTOITEM),
      DEFINE_MESSAGE(WM_CHARTOITEM),
      DEFINE_MESSAGE(WM_SETFONT),
      DEFINE_MESSAGE(WM_GETFONT),
      DEFINE_MESSAGE(WM_QUERYDRAGICON),
      DEFINE_MESSAGE(WM_COMPAREITEM),
      DEFINE_MESSAGE(WM_COMPACTING),
      DEFINE_MESSAGE(WM_NCCREATE),
      DEFINE_MESSAGE(WM_NCDESTROY),
      DEFINE_MESSAGE(WM_NCCALCSIZE),
      DEFINE_MESSAGE(WM_NCHITTEST),
      DEFINE_MESSAGE(WM_NCPAINT),
      DEFINE_MESSAGE(WM_NCACTIVATE),
      DEFINE_MESSAGE(WM_GETDLGCODE),
      DEFINE_MESSAGE(WM_NCMOUSEMOVE),
      DEFINE_MESSAGE(WM_NCLBUTTONDOWN),
      DEFINE_MESSAGE(WM_NCLBUTTONUP),
      DEFINE_MESSAGE(WM_NCLBUTTONDBLCLK),
      DEFINE_MESSAGE(WM_NCRBUTTONDOWN),
      DEFINE_MESSAGE(WM_NCRBUTTONUP),
      DEFINE_MESSAGE(WM_NCRBUTTONDBLCLK),
      DEFINE_MESSAGE(WM_NCMBUTTONDOWN),
      DEFINE_MESSAGE(WM_NCMBUTTONUP),
      DEFINE_MESSAGE(WM_NCMBUTTONDBLCLK),
      DEFINE_MESSAGE(WM_KEYDOWN),
      DEFINE_MESSAGE(WM_KEYUP),
      DEFINE_MESSAGE(WM_CHAR),
      DEFINE_MESSAGE(WM_DEADCHAR),
      DEFINE_MESSAGE(WM_SYSKEYDOWN),
      DEFINE_MESSAGE(WM_SYSKEYUP),
      DEFINE_MESSAGE(WM_SYSCHAR),
      DEFINE_MESSAGE(WM_SYSDEADCHAR),
      DEFINE_MESSAGE(WM_KEYLAST),
      DEFINE_MESSAGE(WM_INITDIALOG),
      DEFINE_MESSAGE(WM_COMMAND),
      DEFINE_MESSAGE(WM_SYSCOMMAND),
      DEFINE_MESSAGE(WM_TIMER),
      DEFINE_MESSAGE(WM_HSCROLL),
      DEFINE_MESSAGE(WM_VSCROLL),
      DEFINE_MESSAGE(WM_INITMENU),
      DEFINE_MESSAGE(WM_INITMENUPOPUP),
      DEFINE_MESSAGE(WM_MENUSELECT),
      DEFINE_MESSAGE(WM_MENUCHAR),
      DEFINE_MESSAGE(WM_ENTERIDLE),
      DEFINE_MESSAGE(WM_MOUSEWHEEL),
      DEFINE_MESSAGE(WM_MOUSEMOVE),
      DEFINE_MESSAGE(WM_LBUTTONDOWN),
      DEFINE_MESSAGE(WM_LBUTTONUP),
      DEFINE_MESSAGE(WM_LBUTTONDBLCLK),
      DEFINE_MESSAGE(WM_RBUTTONDOWN),
      DEFINE_MESSAGE(WM_RBUTTONUP),
      DEFINE_MESSAGE(WM_RBUTTONDBLCLK),
      DEFINE_MESSAGE(WM_MBUTTONDOWN),
      DEFINE_MESSAGE(WM_MBUTTONUP),
      DEFINE_MESSAGE(WM_MBUTTONDBLCLK),
      DEFINE_MESSAGE(WM_PARENTNOTIFY),
      DEFINE_MESSAGE(WM_MDICREATE),
      DEFINE_MESSAGE(WM_MDIDESTROY),
      DEFINE_MESSAGE(WM_MDIACTIVATE),
      DEFINE_MESSAGE(WM_MDIRESTORE),
      DEFINE_MESSAGE(WM_MDINEXT),
      DEFINE_MESSAGE(WM_MDIMAXIMIZE),
      DEFINE_MESSAGE(WM_MDITILE),
      DEFINE_MESSAGE(WM_MDICASCADE),
      DEFINE_MESSAGE(WM_MDIICONARRANGE),
      DEFINE_MESSAGE(WM_MDIGETACTIVE),
      DEFINE_MESSAGE(WM_MDISETMENU),
      DEFINE_MESSAGE(WM_CUT),
      DEFINE_MESSAGE(WM_COPYDATA),
      DEFINE_MESSAGE(WM_COPY),
      DEFINE_MESSAGE(WM_PASTE),
      DEFINE_MESSAGE(WM_CLEAR),
      DEFINE_MESSAGE(WM_UNDO),
      DEFINE_MESSAGE(WM_RENDERFORMAT),
      DEFINE_MESSAGE(WM_RENDERALLFORMATS),
      DEFINE_MESSAGE(WM_DESTROYCLIPBOARD),
      DEFINE_MESSAGE(WM_DRAWCLIPBOARD),
      DEFINE_MESSAGE(WM_PAINTCLIPBOARD),
      DEFINE_MESSAGE(WM_VSCROLLCLIPBOARD),
      DEFINE_MESSAGE(WM_SIZECLIPBOARD),
      DEFINE_MESSAGE(WM_ASKCBFORMATNAME),
      DEFINE_MESSAGE(WM_CHANGECBCHAIN),
      DEFINE_MESSAGE(WM_HSCROLLCLIPBOARD),
      DEFINE_MESSAGE(WM_QUERYNEWPALETTE),
      DEFINE_MESSAGE(WM_PALETTEISCHANGING),
      DEFINE_MESSAGE(WM_PALETTECHANGED),
      DEFINE_MESSAGE(WM_DROPFILES),
      DEFINE_MESSAGE(WM_POWER),
      DEFINE_MESSAGE(WM_WINDOWPOSCHANGED),
      DEFINE_MESSAGE(WM_WINDOWPOSCHANGING),
   };
  
    #undef DEFINE_MESSAGE
    
    constexpr inline cstr get_msg_desc( DWORD message ) {

      for( auto& msg : msg_desc )

        if( message == msg.message ) return msg.desc;
    
      return "null";
    }

  }
}


