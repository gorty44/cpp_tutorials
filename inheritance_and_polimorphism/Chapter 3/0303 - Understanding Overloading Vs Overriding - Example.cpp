#include <iostream>

struct Base {
  virtual void do_something(int i) {
    std::cout << "Base::do_something(" << i << ")\n";
  }
};

struct Derived : Base {
  void do_something(double i) override {
    std::cout << "Derived::do_something(" << i << ")\n";
  }
};

int main()
{
  Derived d;
  d.do_something(1.3);

  Base b;
  b.do_something(1.4);
}
