
#include "ProductByUnit.h"

ProductByUnit::ProductByUnit(const my_string name, const Category category, const double price, const size_t quality) 
 : BaseProduct(name, category, price), quality(quality) {}