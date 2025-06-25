
#include "Category.h"

Category::Category(const MyString& name, const MyString& description)
	: name(name), description(description) {}


MyString Category::getName()
{
	return name;
}

MyString Category::getDescription()
{
	return description;
}
