
#pragma once

#include "my_string.h"

class BaseGiftCard {

public:

	BaseGiftCard();
	BaseGiftCard(const BaseGiftCard& other) = default;
	virtual ~BaseGiftCard() = default;

	BaseGiftCard& operator=(const BaseGiftCard& other) = default;

private:

	static size_t counter;
	my_string code;

};

