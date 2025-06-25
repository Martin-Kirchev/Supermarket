
#pragma once

#include "BaseProduct.h"

class ProductByUnit : public BaseProduct {

public:

	ProductByUnit() = default;
	ProductByUnit(const MyString& name, const MyString& categoryName, const double& price, const size_t& quantity);
	~ProductByUnit() override = default;

	ProductByUnit& operator=(const ProductByUnit& other) = default;
	friend std::ostream& operator<<(std::ostream& os, const ProductByUnit& product);

	ProductType getType() const override;
	size_t getQuantity();

	void print() const override;

private:

	size_t quantity = 0;

};
