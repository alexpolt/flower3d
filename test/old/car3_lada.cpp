
#include "../lib/common.h"

struct car : object {

  $interface( car );

  void virtual update() = 0;

  uint virtual get_counter() = 0;

  //static const uint type_size = 8;

};

struct car_ai : object {

  $interface( car_ai );

  enum dir_t { left, right };

  virtual void steer( dir_t ) = 0;
  virtual uint get_steer( ) const = 0;

};

TP<TN T0> struct car_ai_basic;

struct lada : car {

  $object( lada );

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


owner< car > create_lada() {

  return owner< car >::create< lada >();
}
