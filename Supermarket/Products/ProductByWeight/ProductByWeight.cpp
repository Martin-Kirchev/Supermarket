
#include "ProductByWeight.h"

ProductByWeight::ProductByWeight(const MyString& name, const MyString& categoryName, const double& price, const double& kilograms)
	: BaseProduct(name, categoryName, price), kilograms(kilograms) {}

std::ostream& operator<<(std::ostream& os, const ProductByWeight& product) {

	os << toString(product.getType()) << ':' << product.getName() << ':' << product.getCategoryName() << ':' << product.getPrice() << ':' << product.kilograms;

	return os;
}

bool ProductByWeight::isPossibleToBuy(const double& quantity) const
{
	return this->kilograms >= quantity;
}

void ProductByWeight::removeFromQuantity(const double& quantity) {

	this->kilograms -= quantity;
}

void ProductByWeight::addQuantity(const double& quantity) {

	this->kilograms += quantity;
}

ProductType ProductByWeight::getType() const {

	return ProductType::BY_WEIGHT;
}

double ProductByWeight::getKilograms() {
	return kilograms;
}

void ProductByWeight::printInfo() const {

	std::cout << getName() << " : " << getPrice() << "/kg : " << kilograms << std::endl;

}