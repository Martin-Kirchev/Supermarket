
#pragma once

#include "BaseGiftCard.h"

class MultipleCategoryGiftCard : public BaseGiftCard {

public:

	MultipleCategoryGiftCard() = default;
	MultipleCategoryGiftCard(const MultipleCategoryGiftCard& other) = default;
	virtual ~MultipleCategoryGiftCard() = default;

	MultipleCategoryGiftCard& operator=(const MultipleCategoryGiftCard& other) = default;

};