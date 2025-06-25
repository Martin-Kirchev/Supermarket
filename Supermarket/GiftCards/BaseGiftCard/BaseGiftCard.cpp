
#include "BaseGiftCard.h"

BaseGiftCard::BaseGiftCard(const MyString& code, const size_t& percentage) : code(code), percentage(percentage) {}

bool BaseGiftCard::checkCode(const MyString& code) const {

	return this->code == code;
}

size_t BaseGiftCard::getPercentage() const
{
	return percentage;
}

MyString BaseGiftCard::getCode() const
{
	return code;
}
