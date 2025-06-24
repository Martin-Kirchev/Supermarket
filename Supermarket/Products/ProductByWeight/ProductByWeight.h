
#pragma once

#include "BaseProduct.h"

class ProductByWeight : public BaseProduct {

public:

	ProductByWeight() = default;
	ProductByWeight(const my_string& name, const size_t& categoryID, const double& price, const double& kilograms);
	~ProductByWeight() override = default;

	ProductByWeight& operator=(const ProductByWeight& other) = default;

	ProductType getType() const override;

	void print() const override;

private:

	double kilograms = 0;

};
