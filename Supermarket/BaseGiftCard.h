
#pragma once

#include "my_string.h"
#include "Random.hpp"

class BaseGiftCard {

public:

	BaseGiftCard();
	BaseGiftCard(const BaseGiftCard& other) = default;
	virtual ~BaseGiftCard() = 0;

	BaseGiftCard& operator=(const BaseGiftCard& other) = default;

private:

	static size_t counter;
	my_string code;

};

