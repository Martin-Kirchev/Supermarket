
#pragma once
#pragma warning(disable: 4996)

#include <ctime>

#include "Vector.hpp"
#include "BaseProduct.h"
#include "BaseGiftCard.h"

class Transaction {

public:

	Transaction() = default;
	Transaction(const size_t& ID,const size_t& cashierID);
	Transaction(const Transaction& other) = default;
	~Transaction() = default;

	Transaction& operator=(const Transaction& other) = default;

	size_t getID() const;
	size_t getCashierID() const;

	void calculatePrice();
	double getCurrentPrice() const;

	void addProduct(BaseProduct* product,const size_t& quantity);
	void addGiftCard(BaseGiftCard* giftCard);

	Vector<BaseProduct*> getProducts() const;
	Vector<size_t> getQuantities() const;
	std::ostream& timestampToStream(std::ostream& os) const;

	void printInfo();

private:

	size_t ID;
	size_t cashierID;
	double price;
	Vector<BaseProduct*> products;
	Vector<size_t> quantities;
	BaseGiftCard* giftCard;
	std::time_t timestamp;
	
};
