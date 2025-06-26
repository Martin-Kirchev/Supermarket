
#pragma once

#include "BaseProduct.h"

class ProductByUnit : public BaseProduct {

public:

	ProductByUnit() = default;
	ProductByUnit(const MyString& name, const MyString& categoryName, const double& price, const size_t& quantity);
	~ProductByUnit() override = default;

	ProductByUnit& operator=(const ProductByUnit& other) = default;
	friend std::ostream& operator<<(std::ostream& os, const ProductByUnit& product);

	bool isPossibleToBuy(const double& quantity) const override;
	void removeFromQuantity(const double& quantity) override;
	void addQuantity(const double& quantity) override;

	ProductType getType() const override;
	size_t getQuantity();

	void printInfo() const override;

private:

	size_t quantity = 0;

};
