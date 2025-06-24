
#include "ProductByUnit.h"

ProductByUnit::ProductByUnit(const my_string& name, const size_t& categoryID, const double& price, const size_t& quantity)
 : BaseProduct(name, categoryID, price), quantity(quantity) {}

ProductType ProductByUnit::getType() const {

	return ProductType::BY_UNIT;
}

void ProductByUnit::print() const {

	std::cout << getName() << " : " << getPrice() << " : " << quantity << std::endl;

}