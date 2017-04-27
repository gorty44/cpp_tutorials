struct Base {
  Base(const int t_i) : i(t_i) { }
  
  private:
    int i;
    friend int main();
};

struct Intermediate : private Base // must keep private inheritance
{
  Intermediate(const int t_i) : Base(t_i) {}
  friend int main();
};

struct Derived : Intermediate {
  Derived(const int t_i) : Intermediate(t_i) {} 
};

int main()
{
  return Derived(1).i; // must retain access to i
}
