#include <libunittest/all.hpp>
#include "temp_conversion.hpp"

using namespace unittest::assertions;

TEST(test_celsius_to_fahrenheit_15_returns_59) {
	assert_true(celsius_to_fahrenheit(15) == 59.0, SPOT);
}

TEST(test_celsius_to_fahrenheit_19_returns_66_2) {
	assert_true(celsius_to_fahrenheit(19) == 66.2, SPOT);
}

