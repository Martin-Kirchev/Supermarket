
#include "BaseProduct.h"

BaseProduct::BaseProduct(const my_string& name, const Category& category, const double& price)
	: name(name), price(price), category(category) {}

BaseProduct::~BaseProduct() {}