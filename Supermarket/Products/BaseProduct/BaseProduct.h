
#pragma once

#include "Category.h"
#include "TypeManager.hpp"
#include "IntegerFunction.hpp"
#include "my_string.h"

class BaseProduct {

public:

	BaseProduct() = default;
	BaseProduct(const my_string& name, const size_t& categoryID, const double& price);
	BaseProduct(const BaseProduct& other) = default;
	virtual ~BaseProduct() = default;

	BaseProduct& operator=(const BaseProduct& other) = default;

	my_string getName() const;
	size_t getCategoryID() const;
	double getPrice() const;

	virtual ProductType getType() const = 0;

	virtual void print() const = 0;

private:

	my_string name;
	size_t categoryID;
	double price = 0;

};

