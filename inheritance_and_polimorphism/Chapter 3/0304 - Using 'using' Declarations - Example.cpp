#include <iostream>

struct Base {
  Base(const int t_i) : i(t_i) {}

  void do_something(int) {
    std::cout << "do_something(int)\n";
  }

  int i;
};

struct Derived : Base {
  using Base::Base;
  using Base::do_something;
  void do_something(double) {
    std::cout << "do_something(double)\n";
  }
};


int main()
{
  Derived d(1);
  d.do_something(1);
  d.do_something(1.3);

  std::cout << d.i << '\n';
}
