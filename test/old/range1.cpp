
#include "../lib/common.h"

struct data_t {
  int data[256];
};


constexpr auto fill_data() {

  data_t d{};

  for( auto i : range{ 0, $length( d.data ) } ) d.data[ i ] = i;

  return d;
}

constexpr data_t data = fill_data();


int main () {

  info, data.data, endl;

}


