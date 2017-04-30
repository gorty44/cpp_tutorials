#include <iostream>

struct Base {
	virtual int return_a_value() = 0;
};

int Base::return_a_value() {
	return 1;
}

struct Derived : Base {
	int return_a_value() override {
		return Base::return_a_value();
	}
};

int main() {
	Derived d;
	//Base b;
	std::cout << d.return_a_value() << std::endl;;
}
