#include <memory>
#include <iostream>

struct Base {
	static void destroy(Base* p) {
		delete p;
	}

	static std::unique_ptr<Base, decltype(&destroy)> create_object() {
		return std::unique_ptr<Base, decltype(&destroy)>(new Base(), &destroy);
	}
	
	private : 
		~Base() { std::cout << "Destroyed" << std::endl; }
		Base()  { std::cout << "Created" << std::endl; }
};

struct Derived : Base {};

int main() {
	auto p = Base::create_object();
}
