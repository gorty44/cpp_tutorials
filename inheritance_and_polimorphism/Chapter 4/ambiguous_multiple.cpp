struct Base1 {
	int i = 0;
};
struct Base2 {
	int i = 0;
};

struct Derived : Base1, Base2 {};

int main() {
	Derived d;
	d.i = 2;
}
