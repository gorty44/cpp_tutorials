#include <iostream>

struct CommonData {
  int i = 0;
};

struct Complement : CommonData {
  int operator~() const { return ~i; }
};

struct Negate : CommonData {
  int operator-() const { return -i; }
};

struct Int : Complement, Negate
{
  virtual Int *clone() {
    return new Int(*this);
  }

  Int(const int t_i) 
  {
    Complement::i = t_i;
  }
};

struct MyInt : Int {
  MyInt *clone() {
    return new MyInt(*this);
  }
};

int main()
{
  Int v(42);
  std::cout << -v << '\n';
};
