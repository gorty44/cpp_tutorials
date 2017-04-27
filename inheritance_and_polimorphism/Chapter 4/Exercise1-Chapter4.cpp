// create a mixin that utilizes the < operator
// to provide ==, >, >=, !=, <= operators

struct Int
{
  Int(const int t_value) 
    : value(t_value) 
  {
  }


  int value;

  bool operator<(const Int &rhs) {
    return value < rhs.value;
  }
};