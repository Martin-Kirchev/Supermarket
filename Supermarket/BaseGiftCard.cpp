
#include "BaseGiftCard.h"

size_t BaseGiftCard::counter = 0;

BaseGiftCard::BaseGiftCard() {

	code.push(Random::randomDigit());
	code.push(Random::randomUpper());
	code.pushInteger(counter);
	code.push(Random::randomUpper());
	code.push(Random::randomDigit());

	counter++;
}

BaseGiftCard::~BaseGiftCard() {};