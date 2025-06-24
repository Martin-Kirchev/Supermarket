
#include "BaseProduct.h"

BaseProduct::BaseProduct(const MyString& name, const size_t& categoryID, const double& price)
	: name(name), price(price), categoryID(categoryID) {}

MyString BaseProduct::getName() const {

	return name;
}

size_t BaseProduct::getCategoryID() const {

	return categoryID;
}

double BaseProduct::getPrice() const {

	return price;
}