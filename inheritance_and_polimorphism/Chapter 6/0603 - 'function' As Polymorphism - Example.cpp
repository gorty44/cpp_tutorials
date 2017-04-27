#include <functional>
#include <vector>
#include <iostream>

int add(const int lhs, const int rhs)
{
  return lhs + rhs;
}

int subtract(const int lhs, const int rhs)
{
  return lhs - rhs;
}

struct Callable
{
  int operator()(const int lhs, const int rhs) {
    return lhs * rhs;
  }
};

int main()
{
  std::vector<std::function<int (int, int)>> funcs {
    &add,
    &subtract,
    Callable()
  };


  for (const auto &f : funcs) {
    std::cout << f(4,5) << '\n';
  }
}
