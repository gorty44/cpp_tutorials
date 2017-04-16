
#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

#include <string>

#include "file_system.hpp"
#include "string_utils.hpp"

#include "data.hpp"
#include "find.hpp"


constexpr auto aggregate = [&] (std::string line) {
	auto parts = split(line, "|", true);
	return find(parts[STATE_POS], states.get(), START_IDX, END_IDX);
};

void calculate(const std::string& file_name) {
	std::cout << "Calculate..." << std::endl;
}

void display() {
	std::cout << "Display..." << std::endl;
}


#endif /* FUNCTIONS_HPP_ */
