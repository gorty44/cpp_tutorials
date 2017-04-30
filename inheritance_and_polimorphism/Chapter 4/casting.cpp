#include <iostream>


struct Base1 {
	virtual ~Base1() = default;
};
struct Base2 {
	virtual ~Base2() = default;
};

struct Derived : Base1, Base2 {};

int main() {
	Base1* b = new Base1();
	//static_cast<Base2*>(b);  // unable to cast across the inheritance graph
	std::cout << b << "       " << dynamic_cast<Derived*>(b) << std::endl; // in this case the dynamic_cast returns nullptr
	
	Base2* b2 = new Derived();
	std::cout << b2 << "       " << dynamic_cast<Derived*>(b2) << std::endl; // works fine because b2 can be casted into Derived.
	
	//std::cout << b << "       " << &(dynamic_cast<Derived&>(*b)) << std::endl; // not working because we're trying to cast it to the type that its not
	std::cout << b2 << "       " << &(dynamic_cast<Derived&>(*b2)) << std::endl;
}
