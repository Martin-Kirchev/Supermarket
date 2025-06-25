
#include "ProductByWeight.h"

ProductByWeight::ProductByWeight(const MyString& name, const MyString& categoryName, const double& price, const double& kilograms)
	: BaseProduct(name, categoryName, price), kilograms(kilograms) {}

std::ostream& operator<<(std::ostream& os, const ProductByWeight& product) {

	os << toString(product.getType()) << ':' << product.getName() << ':' << product.getCategoryName() << ':' << product.getPrice() << ':' << product.kilograms;

	return os;
}

ProductType ProductByWeight::getType() const {

	return ProductType::BY_WEIGHT;
}

double ProductByWeight::getKilograms() {
	return kilograms;
}

void ProductByWeight::print() const {

	std::cout << getName() << " : " << getPrice() << "/kg : " << kilograms << std::endl;;

}