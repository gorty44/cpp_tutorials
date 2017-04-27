#include <iostream>

template<typename T>
struct MyStruct
{
  T data;
};


template<typename U>
auto make_struct(U u)
{
  return MyStruct<U>{ u };
}

int main()
{
  auto f = make_struct(5);

  std::cout << f.data << '\n';
}
