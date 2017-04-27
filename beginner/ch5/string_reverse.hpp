#ifndef STRING_REVERSE_HPP_
#define STRING_REVERSE_HPP_

#include <string>
#include <iostream>

std::string get_string_input() {
	std::string in;
	std::cout << "Enter string to reverse: ";
	std::getline(std::cin, in);
	return in;
}

std::string reverse(std::string in) {
	for (std::size_t i = 0; i < in.length()/2; i++) {
		std::string::value_type c = in[i];
		in[i] = in[in.length() - 1 - i];
		in[in.length() - 1 - i] = c;
	}
	return in;
}

#endif //STRING_REVERSE_HPP_
