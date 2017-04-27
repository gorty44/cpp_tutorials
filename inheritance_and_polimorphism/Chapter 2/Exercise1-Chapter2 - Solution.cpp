#include <memory>

struct Base {
  virtual void do_something() {}
};

struct Derived1 : Base {
  virtual void do_semothing() {}
};

struct Derived2 : Base {
  virtual void do_semothing() {}
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
