#include <array>
#include <memory>

template<typename T>
struct Addable
{
  int operator+(const int rhs) const {
    return static_cast<const T*>(this)->val + rhs;
  }
};

struct Numeric : Addable<Numeric>
{
  Numeric(const int t_val)
    : val(t_val)
  {
  }

  int val;
};

template<int I>
struct Int : Numeric
{
  Int() : Numeric(I) { }
};

template<int I>
std::unique_ptr<Numeric> make_int()
{
  return std::make_unique<Int<I>>();
}


int main()
{
  std::array<std::unique_ptr<Numeric>, 30> a
    = { make_int<0>(),  make_int<1>(), make_int<2>(), make_int<3>(), make_int<4>(), make_int<5>(), 
        make_int<6>(), make_int<7>(), make_int<8>(), make_int<9>(), make_int<10>(), make_int<11>(), 
        make_int<12>(), make_int<13>(), make_int<14>(), make_int<15>(), make_int<16>(), make_int<17>(), 
        make_int<18>(), make_int<19>(), make_int<20>(), make_int<21>(), make_int<22>(), make_int<23>(),
        make_int<24>(), make_int<25>(), make_int<26>(), make_int<27>(), make_int<28>(), make_int<29>() };

  int sum = 0;
  for ( const auto &i : a )
  {
    sum += *i + 1;
  }
  return sum;

};