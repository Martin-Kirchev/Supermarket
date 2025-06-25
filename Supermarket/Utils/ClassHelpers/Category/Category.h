
#pragma once

#include "MyString.h"

class Category {

public:

	Category() = default;
	Category(const MyString& name, const MyString& description);
	Category(const Category& other) = default;
	~Category() = default;

	Category& operator=(const Category& other) = default;

	MyString getName();
	MyString getDescription();

private:

	MyString name;
	MyString description;

};
