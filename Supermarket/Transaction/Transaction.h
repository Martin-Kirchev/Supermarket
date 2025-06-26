
#pragma once
#pragma warning(disable: 4996)

#include <ctime>

#include "Vector.hpp"
#include "BaseProduct.h"
#include "SingleCategoryGiftCard.h"
#include "MultipleCategoryGiftCard.h"
#include "AllProductsGiftCard.h"

class Transaction {

public:

	Transaction() = default;
	Transaction(const size_t& ID,const size_t& cashierID);
	Transaction(const Transaction& other) = default;
	~Transaction() = default;

	Transaction& operator=(const Transaction& other) = default;

	size_t getID() const;
	size_t getCashierID() const;

	void useGiftCard();
	void calculatePrice();
	double getCurrentPrice() const;

	void addProduct(BaseProduct* product,const double& quantity);
	void addGiftCard(BaseGiftCard* giftCard);

	bool giftCardIsUsed() const;

	Vector<BaseProduct*> getProducts() const;
	Vector<double> getQuantities() const;
	std::ostream& timestampToStream(std::ostream& os) const;

	void printInfo();

private:

	size_t ID = 0;
	size_t cashierID = 0;
	double price = 0;
	Vector<BaseProduct*> products;
	Vector<double> quantities;
	BaseGiftCard* giftCard;
	std::time_t timestamp;
	
};
