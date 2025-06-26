
#pragma once

#include "BaseGiftCard.h"
#include "Vector.hpp"

class MultipleCategoryGiftCard : public BaseGiftCard {

public:

	MultipleCategoryGiftCard() = default;
	MultipleCategoryGiftCard(const MyString& code, const size_t& percentage);
	MultipleCategoryGiftCard(const MyString& code, const size_t& percentage, const Vector<MyString>& categories);
	MultipleCategoryGiftCard(const MultipleCategoryGiftCard& other) = default;
	virtual ~MultipleCategoryGiftCard() = default;

	MultipleCategoryGiftCard& operator=(const MultipleCategoryGiftCard& other) = default;
	friend std::ostream& operator<<(std::ostream& os, const MultipleCategoryGiftCard& giftCard);

	bool checkForCategory(const MyString& category);
	GiftCardType getType() const override;

private:

	Vector<MyString> categories;

};