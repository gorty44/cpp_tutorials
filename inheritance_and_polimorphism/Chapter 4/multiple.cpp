struct Base1 {};
struct Base2 {};

struct Derived : private Base1, Base2 {};

void do_something(const Base1&) {}

int main() {
	Derived d;
	do_something(d);
}
