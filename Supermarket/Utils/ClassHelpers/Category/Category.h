
#pragma once

#include "MyString.h"

class Category {

public:

	Category() = default;
	Category(const size_t& ID, const MyString& name, const MyString& description);
	Category(const Category& other) = default;
	~Category() = default;

	Category& operator=(const Category& other) = default;

	size_t getID();
	MyString getName();

private:

	size_t ID;
	MyString name;
	MyString description;

};
