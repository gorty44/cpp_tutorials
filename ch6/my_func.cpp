#include <iostream>

void my_func();

int main() {
	my_func();
}

void my_func() {
	int* i = new int(5);
	std::cout << (void*)i << std::endl;
	std::cout << "i: " << *i << std::endl;
	*i = 10;
	std::cout << "i: " << *i << std::endl;
	delete i;
}

