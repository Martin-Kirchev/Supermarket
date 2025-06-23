
#include "ProductByUnit.h"

ProductByUnit::ProductByUnit(const my_string& name, const size_t& categoryID, const double& price, const size_t& quantity)
 : BaseProduct(name, categoryID, price), quantity(quantity) {}