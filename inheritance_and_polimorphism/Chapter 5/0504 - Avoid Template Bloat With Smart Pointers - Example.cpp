#include <memory>
#include <vector>

struct B
{};

template<int I>
struct D : B
{
};

template<int I>
std::unique_ptr<B> factory()
{
  return std::make_unique<D<I>>();
}


int main()
{
  std::vector<std::shared_ptr<B>> v {
    factory<1>(), factory<2>(), factory<3>(), factory<4>(), factory<5>(), 
    factory<6>(), factory<7>(), factory<8>(), factory<9>(), factory<10>(), 
    factory<11>(), factory<12>(), factory<13>(), factory<14>(), factory<15>(), 
    factory<16>(), factory<17>(), factory<18>(), factory<19>(), factory<20>(), 
    factory<21>(), factory<22>(), factory<23>(), factory<24>(), factory<25>(), 
    factory<26>(), factory<27>(), factory<28>(), factory<29>(), factory<30>()
  };


}
