

#include "AllProductsGiftCard.h"

AllProductsGiftCard::AllProductsGiftCard(const MyString& code, const size_t& percentage) : BaseGiftCard(code, percentage){}

std::ostream& operator<<(std::ostream& os, const AllProductsGiftCard& giftCard) {

	os << toString(giftCard.getType()) << ':' << giftCard.getCode() << ':' << giftCard.getPercentage();

	return os;
}

GiftCardType AllProductsGiftCard::getType() const {

	return GiftCardType::ALL_PRODUCTS;
}