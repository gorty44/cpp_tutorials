#ifndef CELSIUS_TO_FAHRENHEIT_TEST__HPP_
#define CELSIUS_TO_FAHRENHEIT_TEST_HPP_

#include "gtest/gtest.h"
#include "temp_conversion.hpp"


TEST(TemperatureConversionTest, celsius_to_fahrenheit){
	EXPECT_EQ(59.0, celsius_to_fahrenheit(15));
}

#endif // CELSIUS_TO_FAHRENHEIT_TEST_HPP_
