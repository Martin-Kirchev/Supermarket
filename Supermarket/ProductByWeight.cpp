
#include "ProductByWeight.h"

ProductByWeight::ProductByWeight(const my_string name, const Category category, const double price, const size_t kilos)
	: BaseProduct(name, category, price), kilos(kilos) {}