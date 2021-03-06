#include <iostream>
#include <stack>

int main() {

	std::cout << "Stack" << std::endl;
	std::cout << "=====" << std::endl;

	std::stack<int> my_stack;

	for (int i = 0; i < 25; i++)
		my_stack.push(i);

	std::cout << "Am I empty? " << (my_stack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "My size is: " << my_stack.size() << std::endl;

	while (!my_stack.empty()) {
		std::cout << my_stack.top() << std::endl;
		my_stack.pop();
	}

}
