
#include "BaseGiftCard.h"

BaseGiftCard::BaseGiftCard(const my_string& code) : code(code) {}

my_string BaseGiftCard::getCode() const {

	return code;
}