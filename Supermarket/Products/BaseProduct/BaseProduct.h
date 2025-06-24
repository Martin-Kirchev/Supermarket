
#pragma once

#include "Category.h"
#include "TypeManager.hpp"
#include "IntegerFunction.hpp"
#include "MyString.h"

class BaseProduct {

public:

	BaseProduct() = default;
	BaseProduct(const MyString& name, const size_t& categoryID, const double& price);
	BaseProduct(const BaseProduct& other) = default;
	virtual ~BaseProduct() = default;

	BaseProduct& operator=(const BaseProduct& other) = default;

	MyString getName() const;
	size_t getCategoryID() const;
	double getPrice() const;

	virtual ProductType getType() const = 0;

	virtual void print() const = 0;

private:

	MyString name;
	size_t categoryID;
	double price = 0;

};

