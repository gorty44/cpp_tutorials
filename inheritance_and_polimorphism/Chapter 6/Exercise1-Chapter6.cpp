#include <cassert>
#include <vector>

struct Function
{
  template<typename Callable>
  explicit Function(Callable) {
    // TODO somehow store the Callable
  }

  int operator()(const int, const int) const
  {
    // TODO call the operator() of the Callable obtained in the constructor
    return 0;
  }
};

int main()
{
  std::vector<Function> f;
  f.emplace_back([](const int x, const int y){ return x - y; });
  f.emplace_back([](const int x, const int y){ return x + y; });

  assert(f[0](2,3) == -1);
  assert(f[1](2,3) == 5);
}
