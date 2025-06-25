
#include "ProductByUnit.h"

ProductByUnit::ProductByUnit(const MyString& name, const MyString& categoryName, const double& price, const size_t& quantity)
 : BaseProduct(name, categoryName, price), quantity(quantity) {}

std::ostream& operator<<(std::ostream& os, const ProductByUnit& product) {

	os << toString(product.getType()) << ':' << product.getName() << ':' << product.getCategoryName() << ':' << product.getPrice() << ':' << product.quantity;

	return os;
}

bool ProductByUnit::isPossibleToBuy(const double& quantity) const
{
	return this->quantity >= quantity;
}

void ProductByUnit::removeFromQuantity(const double& quantity) {

	this->quantity -= quantity;
}

ProductType ProductByUnit::getType() const {

	return ProductType::BY_UNIT;
}

size_t ProductByUnit::getQuantity() {

	return quantity;
}

void ProductByUnit::printInfo() const {

	std::cout << getName() << " : " << getPrice() << " : " << quantity << std::endl;

}