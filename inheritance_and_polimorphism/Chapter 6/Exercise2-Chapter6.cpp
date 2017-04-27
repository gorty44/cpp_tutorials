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
        // any_cast is declared as a friend to actually enable better encapsulation
        // and defined inside of the class to keep all of the code in one place

        // TODO implement
        return T{};
      }


  public:
    template<typename T>
      explicit Any(T t)
      {
        // TODO copy value into our internal holder
      }

    Any(const Any &other) 
    {
      // TODO clone the 'other'
    }


    Any(Any &&) = default;

    template<typename T>
      Any &operator=(T t)
      {
        // TODO copy the value into this object
        return *this;
      }

    Any &operator=(const Any &other)
    {
      // TODO clone the value contained in 'other'
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
