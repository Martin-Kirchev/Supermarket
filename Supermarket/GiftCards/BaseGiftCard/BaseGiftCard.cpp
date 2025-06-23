
#include "BaseGiftCard.h"

size_t BaseGiftCard::counter = 0;

BaseGiftCard::BaseGiftCard(const my_string& code) : code(code) {}

BaseGiftCard::~BaseGiftCard() {};