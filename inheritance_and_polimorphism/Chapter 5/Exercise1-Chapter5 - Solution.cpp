#include <typeinfo>
#include <memory>

struct Base
{
  Base(const std::type_info &ti) : m_ti(ti) { }
  const std::type_info &get_type_info() const {
    return m_ti;
  }
  const std::type_info &m_ti;
};

template<typename T>
struct Derived : Base
{
  Derived() : Base(typeid(T)) { }
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
