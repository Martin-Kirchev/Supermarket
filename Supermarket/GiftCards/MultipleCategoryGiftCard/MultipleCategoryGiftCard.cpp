
#include "MultipleCategoryGiftCard.h"

MultipleCategoryGiftCard::MultipleCategoryGiftCard(const MyString& code, const size_t& percentage) 
	: BaseGiftCard(code, percentage) {}

MultipleCategoryGiftCard::MultipleCategoryGiftCard(const MyString& code, const size_t& percentage, const Vector<MyString>& categories)
	: BaseGiftCard(code, percentage), categories(categories) {
}

std::ostream& operator<<(std::ostream& os, const MultipleCategoryGiftCard& giftCard) {

	os << toString(giftCard.getType()) << ':' << giftCard.getCode() << ':' << giftCard.categories.getSize();

	for (size_t i = 0; i < giftCard.categories.getSize(); i++)
	{
		os << ':' << giftCard.categories[i];
	}

	os << ':' << giftCard.getPercentage();

	return os;
}

bool MultipleCategoryGiftCard::checkForCategory(const MyString& category) {

	for (size_t i = 0; i < categories.getSize(); i++)
	{
		if (categories[i] == category)
			return true;
	}

	return false;
}

GiftCardType MultipleCategoryGiftCard::getType() const {

	return GiftCardType::MULTIPLE_CATEGORY;
}