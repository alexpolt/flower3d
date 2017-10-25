#include <cstdio>
#include <vector>
#include <chrono>

#include "../lib/common.h"


struct car : object {

  $interface( car )

  void virtual update() = 0;

  uint virtual get_counter() = 0;

  //static const uint type_size = 8;

};

struct car_ai : object {

  $interface( car_ai )

  enum dir_t { left, right };

  virtual void steer( dir_t ) = 0;
  virtual uint get_steer( ) const = 0;

};

TP<TN T0> struct car_ai_basic;

struct lada : car {

  $object( lada, car_ai_basic< lada > )

  void update() override {
    $clobber();
    ++*_angle;
  }

  uint get_counter() override {
    return *_angle;
  }

  cstr to_string() const override {
    return "lada";
  }

  //~lada(){ info, "~lada( ", this, " )", endl; }

  uint* _angle = new uint{};
};

struct mazda : lada {
   void update() override {
     $clobber();
    *_angle+=1;
  }
  //~mazda(){ info, "~mazda( ", this, " )", endl; }
};


TP<TN T0> struct car_ai_basic : car_ai {

  $component_template( car_ai_basic )

  void steer( dir_t dir ) override {
    if( dir == left ) 
      --_owner._angle;
    else
      ++_owner._angle;
  }

  uint get_steer() const override {
    return *_owner._angle;
  }

  ~car_ai_basic(){ info, "~car_ai_basic()", endl; }
};



void measure0();
void measure1();

value< car >& create_lada();

int main() {

  info, "compilation date = ", lib::config::compilation_date, endl,
        "program name = ", lib::config::program_name, endl,
        "program version = ", lib::config::program_version, endl;

  $try {

    //value< car > c0 = create_lada();

    value< car > c1{ value< car >::create< lada >() };
    value< car > c0{ move(c1) };

    value<car> car0 = value< car >::create< mazda >();

    info, "log: ", c0, endl;

    auto car_ai0 = car0->get_object( car_ai::tag );

    info, "got ai", endl;

    auto car_object0 = car0->get_object();

    info, "got car_object0", endl;

    printf("car %s steer %s\n", car0->to_string(), car0->get_counter() == car_ai::left ? "left":"right");

    info, "car_ai0->steer", endl;

    car_ai0->steer( car_ai::right );

    printf("car %s steer %s\n", car_ai0->to_string(), car0->get_counter() == car_ai::left ? "left":"right");

    printf("value<car> size = %d\n", $size( car0 ) );

    lib::log::memory.on();

    info, endl, "-- measure0 --", endl;
    measure0();

    info, endl, "-- measure1 --", endl;
    measure1();


  } $catch( lib::error& e ) {

    printf( "%s\n", e.what() );

  }

}

void measure0() {

  vector< value< car > > v;

  auto begin = std::chrono::high_resolution_clock::now();


  range{ 0, 1'000 } $do {

    v << value< car >::create< mazda >();

    range{ 0, 3777 } $do { v << value< car >::create< lada >(); };

    $escape( &v );

    for( auto& e : v ) e->update();

    $clobber();

    v.clear();
  };


  auto end = std::chrono::high_resolution_clock::now();

  auto dt = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();

  printf( "dt = %ld\n", (long)dt );

}

void measure1() {

  vector< lib::owner_ptr<car> > v;

  auto begin = std::chrono::high_resolution_clock::now();


  range{ 0, 1'000 } $do {

    v << lib::make_owner< mazda >();

    range{ 0, 3777 } $do { v << lib::make_owner< lada >(); };

    $escape( &v );

    for( auto& e : v ) e->update();    

    $clobber();

    v.clear();
  };


  auto end = std::chrono::high_resolution_clock::now();

  auto dt = std::chrono::duration_cast< std::chrono::milliseconds >( end - begin ).count();

  printf( "dt = %ld\n", (long)dt );

}


