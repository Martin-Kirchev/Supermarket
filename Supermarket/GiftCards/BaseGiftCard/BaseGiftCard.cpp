
#include "BaseGiftCard.h"

BaseGiftCard::BaseGiftCard(const my_string& code) : code(code) {}

bool BaseGiftCard::checkCode(const my_string& code) const {

	return this->code == code;
}