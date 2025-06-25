
#pragma once

#include "BaseProduct.h"

class ProductByUnit : public BaseProduct {

public:

	ProductByUnit() = default;
	ProductByUnit(const MyString& name, const size_t& categoryID, const double& price, const size_t& quantity);
	~ProductByUnit() override = default;

	ProductByUnit& operator=(const ProductByUnit& other) = default;

	ProductType getType() const override;
	size_t getQuantity();

	void print() const override;

private:

	size_t quantity = 0;

};
