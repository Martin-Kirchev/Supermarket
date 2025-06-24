
#include "BaseGiftCard.h"

BaseGiftCard::BaseGiftCard(const MyString& code) : code(code) {}

bool BaseGiftCard::checkCode(const MyString& code) const {

	return this->code == code;
}