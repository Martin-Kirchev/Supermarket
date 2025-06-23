
#include "BaseProduct.h"

BaseProduct::BaseProduct(const my_string& name, const size_t& categoryID, const double& price)
	: name(name), price(price), categoryID(categoryID) {}

BaseProduct::~BaseProduct() {}