#include <iostream>


struct Helper {
	void do_something() {
		std::cout << "did it" << std::endl;
	}
	protected:
		Helper() {}
};

struct MyClass : Helper {
	void do_work() {
		do_something();
	}
};


int main () {
	Helper* h = new MyClass();
	h->do_something();
	delete h;
}
