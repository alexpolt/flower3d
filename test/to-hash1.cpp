
#include "lib/common.h"
#include "lib/hash.h"

int main() {

  string s{"!"};

  info, "hash of ! = ", lib::hash32<string>::get_hash( s ), endl;

}

