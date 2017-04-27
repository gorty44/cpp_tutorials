#ifndef COMPUTE_INVOICE_HPP_
#define COMPUTE_INVOICE_HPP_

double compute_subtotal(double items[], int count) {
	double total = 0.0;
	for (int i = 0 ; i < count ; i++) 
		total += items[i];
	return total;
}

double apply_sales_discount(double total) {
	return total * (1.0 - 0.05);
}

double apply_sales_tax(double total) {
	return total * (1.0 + 0.09725);
}

double compute_invoice(double items[], int count) {
	double total = compute_subtotal(items, count);
	total = apply_sales_discount(total);
	return apply_sales_tax(total);
}

#endif
