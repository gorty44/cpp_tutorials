struct Base {
  Base(const int t_i) : i(t_i) { }
  
  protected:
    int i;
};

struct Intermediate : private Base // must keep private inheritance
{
  using Base::Base;
  using Base::i;
};

struct Derived : Intermediate {
  using Intermediate::Intermediate;
};

int main()
{
  return Derived(1).i; // must retain access to i
}
