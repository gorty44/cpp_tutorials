#include <memory>

struct B
{
  int get() { return 0; }
//  virtual int get() { return 0; }
};

struct D : B
{
//  int get() override { return 1; }
};

struct D2 : D
{
//  int get() override { return 2; }
};


int main(int argc, const char *[])
{
  std::unique_ptr<B> p;
  if (argc == 1) {
    p = std::make_unique<D2>();
  } else if (argc == 2) {
    p = std::make_unique<D>();
  } else {
    p = std::make_unique<B>();
  }

  int count = 0;

  for (int i = 0; i < 10000000; ++i) {
    count += p->get();
  }

  return count;
}
