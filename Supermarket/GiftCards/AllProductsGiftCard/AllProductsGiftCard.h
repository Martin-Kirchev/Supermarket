
#pragma once

#include "BaseGiftCard.h"

class AllProductsGiftCard : public BaseGiftCard {

public:

	AllProductsGiftCard() = default;
	AllProductsGiftCard(const AllProductsGiftCard& other) = default;
	virtual ~AllProductsGiftCard() = default;

	AllProductsGiftCard& operator=(const AllProductsGiftCard& other) = default;

};