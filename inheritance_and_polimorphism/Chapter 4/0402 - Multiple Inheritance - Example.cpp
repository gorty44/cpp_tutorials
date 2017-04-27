struct Base1 {
  int i;
};

struct Base2 {
  int i;
};

struct Derived : private Base1, Base2 {
};

int main() {
  Derived d;

  d.i = 3;


}