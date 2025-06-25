
#include "SingleCategoryGiftCard.h"

SingleCategoryGiftCard::SingleCategoryGiftCard(const MyString& code, const size_t& percentage, const MyString& categoryName) 
	: BaseGiftCard(code, percentage), categoryName(categoryName) {}

std::ostream& operator<<(std::ostream& os, const SingleCategoryGiftCard& giftCard) {

	os << toString(giftCard.getType()) << ':' << giftCard.getCode() << ':' << giftCard.categoryName << ':' << giftCard.getPercentage();

	return os;
}

GiftCardType SingleCategoryGiftCard::getType() const {

	return GiftCardType::SINGLE_CATEGORY;
}

MyString SingleCategoryGiftCard::getCategoryName() const {

	return categoryName;
}