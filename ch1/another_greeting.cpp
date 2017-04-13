#include <iostream>
#include <string>

auto another_greeting = [] (std::string m) {
	return std::string("Hello ") + m;
};

constexpr auto greeting = "hello world!";

int main() {
	std::cout << another_greeting("Dawid!") << std::endl;
	std::cout << greeting << std::endl;
}

