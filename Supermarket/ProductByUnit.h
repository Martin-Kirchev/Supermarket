
#pragma once

#include "BaseProduct.h"

class ProductByUnit : public BaseProduct {

public:

	ProductByUnit() = default;
	ProductByUnit(const my_string name, const Category category, const double price, const size_t quality);
	~ProductByUnit() override = default;

	ProductByUnit& operator=(const ProductByUnit& other) = default;

private:

	size_t quality = 0;

};
