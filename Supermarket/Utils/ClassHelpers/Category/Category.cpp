
#include "Category.h"

Category::Category(const size_t& ID, const my_string& name, const my_string& description)
	: ID(ID), name(name), description(description) {}

size_t Category::getID() {

	return ID;
}

my_string Category::getName()
{
	return name;
}
