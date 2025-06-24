
#pragma once

#include "my_string.h"
#include "TypeManager.hpp"
#include "Random.hpp"

class BaseGiftCard {

public:

	BaseGiftCard() = default;
	BaseGiftCard(const my_string& code);
	BaseGiftCard(const BaseGiftCard& other) = default;
	virtual ~BaseGiftCard() = default;

	BaseGiftCard& operator=(const BaseGiftCard& other) = default;

	my_string getCode() const;
	virtual GiftCardType getType() const = 0;
	
private:

	my_string code;

};

