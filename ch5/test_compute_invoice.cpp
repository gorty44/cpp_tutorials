#include <libunittest/all.hpp>
#include "compute_invoice.hpp"

using namespace unittest::assertions;

TEST(test_helpers) {
	assert_true(apply_sales_discount(1.0) == 0.95);
	assert_true(apply_sales_tax(1.0) == 1.09725);
	double bag[] = {2.0,3.0,4.0};
	assert_true(compute_subtotal(bag, 3) == 9);
}

TEST(test_compute_invoice) {
	double bag[] = {2.0,3.0,4.0};
	assert_true(compute_invoice(bag,3) == 9.38149);
}



