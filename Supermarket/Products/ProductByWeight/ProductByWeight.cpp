
#include "ProductByWeight.h"

ProductByWeight::ProductByWeight(const my_string& name, const size_t& categoryID, const double& price, const double& kilograms)
	: BaseProduct(name, categoryID, price), kilograms(kilograms) {}

ProductType ProductByWeight::getType() const {

	return ProductType::BY_WEIGHT;
}

void ProductByWeight::print() const {

	std::cout << getName() << " : " << getPrice() << "/kg : " << kilograms << std::endl;;

}