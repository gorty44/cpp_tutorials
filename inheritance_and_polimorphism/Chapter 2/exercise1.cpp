#include <memory>
#include <iostream>



struct Base {
  virtual void do_something() { std::cout << "Base class method\n"; }
  virtual ~Base() = default;

  // RULE OF 0
  Base() = default;
  Base(const Base&) = default;
  Base(Base&&) = default; // move constructor
  Base& operator=(const Base&) = default;
  Base& operator=(Base&&) = default;
};

struct Derived1 final : Base {
  void do_something() override { std::cout << "Derived1 method\n"; }
};

struct Derived2 final : Base {
  void do_something() override { std::cout << "Derived2 method\n"; }
};


enum class Type {
  Base_Type,
  Derived1_Type,
  Derived2_Type
};


std::unique_ptr<Base> make_object(const Type &t) {
  switch(t) {
    case Type::Base_Type:
      return std::make_unique<Base>();
    case Type::Derived1_Type:
      return std::make_unique<Derived1>();
    case Type::Derived2_Type:
      return std::make_unique<Derived2>();
  }
}


int main() {
	std::unique_ptr<Base> object = make_object(Type::Derived1_Type);
	object->do_something();

	std::unique_ptr<Base> object2 = make_object(Type::Derived2_Type);
	object2->do_something();

	std::unique_ptr<Base> object3 = make_object(Type::Base_Type);
	object3->do_something();

}
