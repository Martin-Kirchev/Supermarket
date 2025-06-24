
#pragma once

#include "BaseGiftCard.h"

class SingleCategoryGiftCard : public BaseGiftCard {

public:

	SingleCategoryGiftCard() = default;
	SingleCategoryGiftCard(const SingleCategoryGiftCard& other) = default;
	virtual ~SingleCategoryGiftCard() = default;

	SingleCategoryGiftCard& operator=(const SingleCategoryGiftCard& other) = default;

	GiftCardType getType() const override;

};