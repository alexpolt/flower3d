
#include "lib/common.h"
#include "os/file.h"

int main() {

  lib::os::file f{ "eof1.txt" };

  f.open();

  vector_b b;

  f.read( b, 20 );

  if( f.eof() ) info, "eof\n";

  info, "size = ", b.size(), endl;

  b << '\0';

  info, b.data(), endl;

}

