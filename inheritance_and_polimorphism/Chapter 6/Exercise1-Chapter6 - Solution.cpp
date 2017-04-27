#include <cassert>
#include <vector>
#include <memory>

struct Function
{
  private:
    struct Callable_Impl_Base
    {
      virtual ~Callable_Impl_Base() = default;
      Callable_Impl_Base() = default;
      Callable_Impl_Base(const Callable_Impl_Base &) = delete;
      Callable_Impl_Base(Callable_Impl_Base &&) = delete;
      Callable_Impl_Base& operator=(const Callable_Impl_Base &) = delete;
      Callable_Impl_Base& operator=(Callable_Impl_Base &&) = delete;
      virtual int operator()(const int, const int) const = 0;
    };

    template<typename Callable>
    struct Callable_Impl final : Callable_Impl_Base
    {
      Callable_Impl(Callable c)
        : m_c(std::move(c))
      {
      }

      int operator()(const int x, const int y) const override
      {
        return m_c(x, y);
      }

      Callable m_c;
    };

    std::unique_ptr<Callable_Impl_Base> m_impl;

  public:
    template<typename Callable>
      explicit Function(Callable c)
      : m_impl(std::make_unique<Callable_Impl<Callable>>(std::move(c)))
      {
      }

    int operator()(const int x, const int y) const
    {
      return (*m_impl)(x, y);
    }


};

int main()
{
  std::vector<Function> f;
  f.emplace_back([](const int x, const int y){ return x - y; });
  f.emplace_back([](const int x, const int y){ return x + y; });

  Function f2 = f[0];

  assert(f[0](2,3) == -1);
  assert(f[1](2,3) == 5);
}
