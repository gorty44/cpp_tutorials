#include <memory>
#include <string>

struct B
{
  virtual int get() { return 0; }

  //virtual ~B() = default;

  B() = default;
  B(const B&) = default;
  B(B&&) = default;
  B&operator=(const B&) = default;
  B&operator=(B &&) = default;

  std::string s;
};

struct D : B
{
  int get() override { return 1; }
};

struct D2 : D
{
  int get() override { return 2; }
};


int main(int argc, const char *[])
{
  for (int i = 0; i < 1000000; ++i) {
    if (argc == 1) {
      std::unique_ptr<B> p = std::make_unique<D2>();
    } else if (argc == 2) {
      std::unique_ptr<B> p = std::make_unique<D>();
    } else {
      std::unique_ptr<B> p = std::make_unique<B>();
    }
  }
}
