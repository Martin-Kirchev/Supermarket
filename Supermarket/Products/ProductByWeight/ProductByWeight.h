
#pragma once

#include "BaseProduct.h"

class ProductByWeight : public BaseProduct {

public:

	ProductByWeight() = default;
	ProductByWeight(const MyString& name, const MyString& categoryName, const double& price, const double& kilograms);
	~ProductByWeight() override = default;

	ProductByWeight& operator=(const ProductByWeight& other) = default;
	friend std::ostream& operator<<(std::ostream& os, const ProductByWeight& product);

	ProductType getType() const override;
	double getKilograms();

	void print() const override;

private:

	double kilograms = 0;

};
