
#pragma once

#include "BaseProduct.h"

class ProductByWeight : public BaseProduct {

public:

	ProductByWeight() = default;
	ProductByWeight(const my_string name, const Category category, const double price, const size_t kilos);
	~ProductByWeight() override = default;

	ProductByWeight& operator=(const ProductByWeight& other) = default;

private:

	size_t kilos = 0;

};
