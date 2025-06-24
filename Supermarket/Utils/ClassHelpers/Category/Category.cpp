
#include "Category.h"

Category::Category(const size_t& ID, const MyString& name, const MyString& description)
	: ID(ID), name(name), description(description) {}

size_t Category::getID() {

	return ID;
}

MyString Category::getName()
{
	return name;
}
