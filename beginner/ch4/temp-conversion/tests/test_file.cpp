#include "temp_converter.hpp"

using c2f = celsius_to_fahrenheit;

void test_celsius_to_fahrenheit(double c) {
	ASSERT_TRUE(c2f(15) == 59.0);
}

