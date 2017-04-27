#include <iostream>

class Base {
	public:
		Base(const Base& object) : a(object.a), b(object.b) {
			std::cout << "Copy constructor" << std::endl;
		}
		Base(int i, double j = 15.5) : a(i), b(j) {
			std::cout << "Constructor with one default argument" << std::endl;
		}

		Base() : Base(0,0) {}
	
		void print() {
			std::cout << "(" << this->a << ", " << this->b << ")" << std::endl;
		}


	protected:
		int a;
		double b;
};
// public inheritance
class DerivedPublicly : public Base {
	public:
		DerivedPublicly() : Base(1) {}
};

// protected inheritance
class DerivedProtected : protected Base {
	public:
	       	DerivedProtected() : Base(2) {}
};

class DerivedPrivately : Base {
	public:
		DerivedPrivately() : Base(3) {}
};

int main() {
	Base b;
	b.print();

	DerivedPublicly d;
	d.print();


	DerivedProtected d2;
	//d2.print();  void print() from Base is not visible in this context
	
	DerivedPrivately d3;
	//d3.print();  void print() from Base is not visible in this context
}
