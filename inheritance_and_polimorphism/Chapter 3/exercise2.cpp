#include <iostream>

struct Base {
  void print(const char c) {
    std::cout << c << '\n';
  }
};

struct Derived : Base {
  using Base::print;
  void print(int i) {
    std::cout << i << '\n';
  }
};

int main()
{
  Derived d;
  d.print('A');
}
