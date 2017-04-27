#include <cassert>
#include <stdexcept>
#include <memory>
#include <typeindex>


struct bad_any_cast : std::runtime_error
{
  bad_any_cast() 
    : std::runtime_error("Bad Any Cast") 
  {
  }

  virtual ~bad_any_cast() noexcept = default;
  bad_any_cast(bad_any_cast &&) = default;
  bad_any_cast(const bad_any_cast &) = default;
  bad_any_cast &operator=(bad_any_cast &&) = default;
  bad_any_cast &operator=(const bad_any_cast &) = default;
};


class Any;

template<typename T> T any_cast(const Any &);

class Any
{
  public:
    template<typename T>
      friend T any_cast(const Any &a)
      {
        if (a.m_impl->m_ti == typeid(T))
        {
          return *static_cast<T*>(a.m_impl->data());
        } else {
          throw bad_any_cast();
        }
      }

  private:

    struct Any_Impl_Base
    {
      explicit Any_Impl_Base(std::type_index t_ti) : m_ti(std::move(t_ti)) {}

      virtual ~Any_Impl_Base() = default;
      // TODO delete other special functions
      virtual std::unique_ptr<Any_Impl_Base> clone() = 0;
      virtual void* data() = 0;
      std::type_index m_ti;
    };

    template<typename T>
    struct Any_Impl final : Any_Impl_Base
    {
      Any_Impl(T t) : Any_Impl_Base(typeid(T)), m_data(std::move(t))
      {
      }

      std::unique_ptr<Any_Impl_Base> clone() override
      {
        return std::make_unique<Any_Impl<T>>(m_data);
      }

      void* data() override {
        return &m_data;
      }

      T m_data;
    };

    std::unique_ptr<Any_Impl_Base> m_impl;

  public:
    template<typename T>
      explicit Any(T t)
        : m_impl(std::make_unique<Any_Impl<T>>(std::move(t)))
      {
      }

    Any(const Any &other)
      : m_impl(other.m_impl->clone())
    {
    }


    Any(Any &&) = default;

    template<typename T>
      Any &operator=(T t)
      {
        m_impl = std::make_unique<Any_Impl<T>>(std::move(t));
        return *this;
      }

    Any &operator=(const Any &other)
    {
      m_impl = other.m_impl->clone();
      return *this;
    }

    Any &operator=(Any &&) = default;
    ~Any() = default;
};


int main()
{
  Any a(5);

  assert(any_cast<int>(a) == 5);

  try {
    any_cast<float>(a);
    assert(false); // shouldn't be able to reach this line
  } catch (const bad_any_cast &) {
    // should jump to here
  }
}


