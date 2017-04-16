#ifndef GEOMETRY_TEST_HPP_
#define GEOMETRY_TEST_HPP_


#include "gtest/gtest.h"
#include "geometry.h"


TEST(GeometryTest, AreaOfSquareTest) {
	EXPECT_DOUBLE_EQ(25.0, area_of_square(5.0,5.0));
}

TEST(GeometryTest, AreaOfSquareTestNotEqual) {
	EXPECT_DOUBLE_EQ(20, area_of_square(2,2));
}

#endif
