#include <iostream>

struct Base {
	Base(const int& i) : _i(i) {}
	void do_something(int i) {
		std::cout << "do_something(int)\n";
	}
	private:
		int _i;
};

struct Derived : Base {
	using Base::Base; // instead of Derived(const int& i) : Base(i) {}
	using Base::do_something; // pulling do_something method from Base class
	void do_something(double i) {
		std::cout << "do_something(double)\n";
	}
};


int main() {
	Derived d(1);
	d.do_something(5.2);
	Base b(2);
	b.do_something(2);
	b.do_something(1.2);	
}
