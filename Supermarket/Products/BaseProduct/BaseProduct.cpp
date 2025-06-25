
#include "BaseProduct.h"

BaseProduct::BaseProduct(const MyString& name, const MyString& categoryName, const double& price)
	: name(name), price(price), categoryName(categoryName) {}

MyString BaseProduct::getName() const {

	return name;
}

MyString BaseProduct::getCategoryName() const {

	return categoryName;
}

double BaseProduct::getPrice() const {

	return price;
}