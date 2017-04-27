struct Base
{
  virtual int get_a_value() = 0;
};

int Base::get_a_value() {
  return 1;
}

struct Derived : Base {
  int get_a_value() override {
    return Base::get_a_value();
  }
};

int main()
{
  Derived d;
}
