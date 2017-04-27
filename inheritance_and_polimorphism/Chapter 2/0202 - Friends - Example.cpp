struct Base
{
  public:    int i;
  protected: int j;
  private:   int k;
};

struct Derived : Base
{
  public:    int l;
  protected: int m;
  private:   int n;  
};

int main()
{
  Derived d;
  
  d.i = 1;
  d.j = 2;
  d.k = 3;
  d.l = 4;
  d.m = 5;
  d.n = 6;
}