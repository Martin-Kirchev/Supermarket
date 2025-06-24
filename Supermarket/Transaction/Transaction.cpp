
#include "Transaction.h"


Transaction::Transaction(const size_t& ID, const size_t& cashierID) : ID(ID), cashierID(cashierID), price(0), giftCard(nullptr), timestamp(NULL) {}

size_t Transaction::getID() const {

	return ID;
}

size_t Transaction::getCashierID() const {

	return cashierID;
}

void Transaction::calculatePrice() {

	int productsSize = products.size();
	double tempPrice = 0;

	for (size_t i = 0; i < productsSize; i++)
	{

		if (products[i]->getType() == ProductType::BY_UNIT) {

			tempPrice += (products[i]->getPrice() * quantities[i]);
			continue;
		}

		if (products[i]->getType() == ProductType::BY_WEIGHT) {

			tempPrice += (products[i]->getPrice()) * (quantities[i] / 1000.0);
			continue;
		}
	}

	price = tempPrice;
}

double Transaction::getCurrentPrice() const {

	return price;
}

void Transaction::addProduct(BaseProduct* product, const size_t& quantity) {

	this->products.push_back(product);
	this->quantities.push_back(quantity);
}



