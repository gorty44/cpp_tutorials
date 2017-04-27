class Base
{
public:
  virtual ~Base() = default;
  Base() = default;
  Base(const Base &) = default;
  Base(Base &&) = default;
  Base &operator=(const Base &) = default;
  Base &operator=(Base &&) = default;

  virtual void do_something() = 0;
};

class Derived : public Base
{
  void do_something() {}
};


int main()
{
  Derived d;
}
