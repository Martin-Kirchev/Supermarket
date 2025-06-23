
#include "ProductByUnit.h"

ProductByUnit::ProductByUnit(const my_string& name, const Category& category, const double& price, const size_t& quantity)
 : BaseProduct(name, category, price), quantity(quantity) {}