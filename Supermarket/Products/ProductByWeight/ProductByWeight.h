
#pragma once

#include "BaseProduct.h"

class ProductByWeight : public BaseProduct {

public:

	ProductByWeight() = default;
	ProductByWeight(const MyString& name, const MyString& categoryName, const double& price, const double& kilograms);
	~ProductByWeight() override = default;

	ProductByWeight& operator=(const ProductByWeight& other) = default;
	friend std::ostream& operator<<(std::ostream& os, const ProductByWeight& product);

	bool isPossibleToBuy(const double& quantity) const;
	void removeFromQuantity(const double& quantity);

	ProductType getType() const override;
	double getKilograms();

	void printInfo() const override;

private:

	double kilograms = 0;

};
