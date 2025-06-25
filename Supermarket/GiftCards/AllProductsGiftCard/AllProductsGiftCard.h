
#pragma once

#include "BaseGiftCard.h"

class AllProductsGiftCard : public BaseGiftCard {

public:

	AllProductsGiftCard() = default;
	AllProductsGiftCard(const MyString& code, const size_t& percentage);
	AllProductsGiftCard(const AllProductsGiftCard& other) = default;
	virtual ~AllProductsGiftCard() = default;

	AllProductsGiftCard& operator=(const AllProductsGiftCard& other) = default;
	friend std::ostream& operator<<(std::ostream& os, const AllProductsGiftCard& giftCard);

	GiftCardType getType() const override;

};