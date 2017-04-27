#include <iostream>


class Base {
	public:
		virtual ~Base() { std::cout << "~Base\n"; }
};

class Derived : public Base {
	public:
		~Derived() { std:: cout << "~Derived\n"; }
};

int main() {
	Derived* b = new Derived();
	delete b;
}
