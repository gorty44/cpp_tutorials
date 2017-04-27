#include <iostream>
#include <memory>

struct CommonData {
  int i = 0;
};

struct Complement : virtual CommonData {
  int operator~() const { return ~i; }
};

struct Negate : virtual CommonData {
  int operator-() const { return -i; }
};

struct Int : Complement, Negate
{
  virtual std::unique_ptr<Int> clone() {
    return std::make_unique<Int>(*this);
  }

  Int(const int t_i) 
  {
    Complement::i = t_i;
  }
};

struct MyInt : Int {
  std::unique_ptr<Int> clone() override {
    return std::make_unique<MyInt>(*this);
  }
};

int main()
{
  Int v(42);
  std::cout << -v << '\n';
};
