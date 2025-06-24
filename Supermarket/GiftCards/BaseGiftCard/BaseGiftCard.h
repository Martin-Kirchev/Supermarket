
#pragma once

#include "MyString.h"
#include "TypeManager.hpp"
#include "Random.hpp"

class BaseGiftCard {

public:

	BaseGiftCard() = default;
	BaseGiftCard(const MyString& code);
	BaseGiftCard(const BaseGiftCard& other) = default;
	virtual ~BaseGiftCard() = default;

	BaseGiftCard& operator=(const BaseGiftCard& other) = default;

	bool checkCode(const MyString& code) const;

	virtual GiftCardType getType() const = 0;
	
private:

	MyString code;

};

