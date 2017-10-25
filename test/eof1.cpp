
#include <cstdio>


int main() {

  FILE* f = fopen( "eof1.txt", "rb" );

  unsigned char buf[256];

  auto sz = fread( buf, 1, 7, f );

  buf[ sz ] = '\0';

  printf( "read %d bytes:\n===\n%s", sz, buf );

  if( feof( f ) ) printf("\n===\neof true\n");

  fclose( f );
}

