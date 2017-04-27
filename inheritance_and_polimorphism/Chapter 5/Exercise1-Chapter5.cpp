#include <typeinfo>
#include <memory>

struct Base
{
  virtual const std::type_info &get_type_info() const = 0;
  virtual ~Base() = default;
  Base() = default;
  Base(const Base &) = default;
  Base(Base &&) = default;
  Base &operator=(const Base &) = default;
  Base &operator=(Base &&) = default;
};

template<typename T>
struct Derived : Base
{
  const std::type_info &get_type_info() const override {
    return typeid(T);
  }
};

int main(int argc, const char *[])
{
  for (int i = 0; i < 1000000; ++i) {
    if (argc == 0) {
      std::unique_ptr<Base> p = std::make_unique<Derived<int>>();
      if (p->get_type_info() != typeid(int)) throw std::runtime_error("type not properly stored");
    } else if (argc == 1) {
      std::unique_ptr<Base> p = std::make_unique<Derived<double>>();
      if (p->get_type_info() != typeid(double)) throw std::runtime_error("type not properly stored");
    } else {
      std::unique_ptr<Base> p = std::make_unique<Derived<float>>();
      if (p->get_type_info() != typeid(float)) throw std::runtime_error("type not properly stored");
    }
  }
}
