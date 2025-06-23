
#pragma once

#include "Category.h"
#include "my_string.h"

class BaseProduct {

public:

	BaseProduct() = default;
	BaseProduct(const my_string& name, const Category& category, const double& price);
	virtual ~BaseProduct() = 0;

	BaseProduct& operator=(const BaseProduct& other) = default;

private:

	my_string name;
	Category category;
	double price = 0;

};

