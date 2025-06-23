
#pragma once

#include "my_string.h"

class Category {

public:

	Category() = default;
	Category(const size_t& ID, const my_string& name, const my_string& description);
	Category(const Category& other) = default;
	~Category() = default;

	Category& operator=(const Category& other) = default;

private:

	size_t ID;
	my_string name;
	my_string description;

};
