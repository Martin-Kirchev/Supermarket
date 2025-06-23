
#include "ProductByWeight.h"

ProductByWeight::ProductByWeight(const my_string& name, const size_t& categoryID, const double& price, const size_t& kilograms)
	: BaseProduct(name, categoryID, price), kilograms(kilograms) {}