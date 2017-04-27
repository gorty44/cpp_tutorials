#include <iostream>


class Test {
	int i = 15;
	public:
		struct Nested {
			static int get_private_i(const Test& t) {
				return t.i;
			}
		};
};

int main() {
	Test t;
	return Test::Nested::get_private_i(t);
}
