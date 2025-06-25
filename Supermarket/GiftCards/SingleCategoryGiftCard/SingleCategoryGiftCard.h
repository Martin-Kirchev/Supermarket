
#pragma once

#include "BaseGiftCard.h"

class SingleCategoryGiftCard : public BaseGiftCard {

public:

	SingleCategoryGiftCard() = default;
	SingleCategoryGiftCard(const MyString& code, const size_t& percentage, const MyString& categoryName);
	SingleCategoryGiftCard(const SingleCategoryGiftCard& other) = default;
	virtual ~SingleCategoryGiftCard() = default;

	SingleCategoryGiftCard& operator=(const SingleCategoryGiftCard& other) = default;
	friend std::ostream& operator<<(std::ostream& os, const SingleCategoryGiftCard& giftCard);

	GiftCardType getType() const override;
	MyString getCategoryName() const;

private:

	MyString categoryName;

};