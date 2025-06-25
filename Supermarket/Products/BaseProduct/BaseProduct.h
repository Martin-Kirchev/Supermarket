
#pragma once

#include "Category.h"
#include "TypeManager.hpp"
#include "IntegerFunction.hpp"
#include "MyString.h"

class BaseProduct {

public:

	BaseProduct() = default;
	BaseProduct(const MyString& name, const MyString& categoryName, const double& price);
	BaseProduct(const BaseProduct& other) = default;
	virtual ~BaseProduct() = default;

	BaseProduct& operator=(const BaseProduct& other) = default;

	MyString getName() const;
	MyString getCategoryName() const;
	double getPrice() const;

	virtual bool isPossibleToBuy(const double& quantity) const = 0;
	virtual void removeFromQuantity(const double& quantity) = 0;

	virtual ProductType getType() const = 0;

	virtual void printInfo() const = 0;

private:

	MyString name;
	MyString categoryName;
	double price = 0;

};

