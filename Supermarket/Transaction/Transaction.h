
#pragma once

#include <ctime>;

#include "my_vector.hpp"
#include "BaseProduct.h"
#include "BaseGiftCard.h"

class Transaction {

public:

	Transaction(const size_t& ID,const size_t& cashierID);

	size_t getID() const;
	size_t getCashierID() const;

	void calculatePrice();
	double getCurrentPrice() const;

	void addProduct(BaseProduct* product,const size_t& quantity);
	void addGiftCard(BaseGiftCard* giftCard);

	my_string timestampToString() const;

private:

	size_t ID;
	size_t cashierID;
	double price;
	my_vector<BaseProduct*> products;
	my_vector<size_t> quantities;
	BaseGiftCard* giftCard;
	std::time_t timestamp;
	
};
