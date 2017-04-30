/*
 * In this example we have 3 unmerged Common classes
 *
 *	Common	Common	Common
 *         |       |       |
 *       Base1	 Base2    Base3
 *            \    |    /
 *               Derived
 *
 *
 *
 */
#include <iostream>


struct Common {
	int i;
};

struct Base1 : Common {};
struct Base2 : Common {};
struct Base3 : Common {};

struct Derived : Base1, Base2, Base3 {};

int main() {
	Derived d;

	d.Base1::i = 1;
	d.Base2::i = 2;
	d.Base3::i = 3;

	std::cout << d.Base1::i << ',' << d.Base2::i << ',' << d.Base3::i << std::endl;
}


