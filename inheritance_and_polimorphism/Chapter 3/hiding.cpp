#include <iostream>

struct Base {
	void do_something(int i) {
		std::cout << "Base::do_something(" << i << ")\n";
	}
};

struct Derived : Base {
	void do_something(double i) {
		std::cout << "Derived::do_something(" << i << ")\n";
	}
};


int main() {
	Derived d;
	d.do_something(5); // it appears that Base class method will be invoked cause argument is int, but
				// Derived class has actually hidden the Base class method
	Base b;
	b.do_something(2);
	b.do_something(1.2);	
}
