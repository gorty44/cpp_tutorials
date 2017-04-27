// create a mixin that utilizes the < operator
// to provide ==, >, >=, !=, <= operators

template<typename T>
struct Comparisons
{
  const T& obj() const {
    return static_cast<T&>(*this);
  }

  bool operator==(const T &rhs) const {
    return !(obj() < rhs || rhs < obj());
  }

  bool operator>(const T &rhs) const {
    return !(obj() < rhs || obj() == rhs);
  }

  bool operator>=(const T &rhs) const {
    return obj() > rhs || obj() == rhs;
  }

  bool operator<=(const T &rhs) const {
    return obj() < rhs || obj() == rhs;
  }

  bool operator!=(const T &rhs) const {
    return !(obj() == rhs);
  }
};

struct Int : Comparisons<Int>
{
  Int(const int t_value) 
    : value(t_value) 
  {
  }


  int value;

  bool operator<(const Int &rhs) const {
    return value < rhs.value;
  }
};

int main()
{
  Int lhs(1);
  Int rhs(2);

  lhs < rhs;
  lhs == rhs;
  lhs > rhs;
  lhs <= rhs;
  lhs >= rhs;
  lhs != rhs;

}