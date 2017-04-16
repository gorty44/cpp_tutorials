#include "string_reverse.hpp"
#include <libunittest/all.hpp>

using namespace unittest::assertions;

TEST(test_string_reverse) {
	assert_true(reverse("hello") == "olleh", SPOT);
}

