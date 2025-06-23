
#pragma once

#include "Category.h"
#include "my_string.h"

class BaseProduct {

public:

	BaseProduct() = default;
	BaseProduct(const my_string& name, const size_t& categoryID, const double& price);
	virtual ~BaseProduct() = 0;

	BaseProduct& operator=(const BaseProduct& other) = default;

private:

	my_string name;
	size_t categoryID;
	double price = 0;

};

