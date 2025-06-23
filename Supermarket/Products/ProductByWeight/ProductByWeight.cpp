
#include "ProductByWeight.h"

ProductByWeight::ProductByWeight(const my_string& name, const Category& category, const double& price, const size_t& kilograms)
	: BaseProduct(name, category, price), kilograms(kilograms) {}