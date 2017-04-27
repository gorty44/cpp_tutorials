#include "site.hpp"
#include <iostream>


void print_name_by_pointer(const Site* s) {
	if (s != nullptr)
		std::cout << s->name() << std::endl;
}

void print_name_by_reference(const Site& s) {
	std::cout << s.name() << std::endl;
}

void print_name_by_value(const Site s) {
	std::cout << s.name() << std::endl;
}


int main(int argc, char* argv[]) {
	int length = 5;
	Site s;
	s.set_name("dawid");
	print_name_by_pointer(&s);
	print_name_by_reference(s);
	print_name_by_value(s);
}

