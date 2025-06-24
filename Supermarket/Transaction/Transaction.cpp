
#include "Transaction.h"


Transaction::Transaction(const size_t& ID, const size_t& cashierID) : ID(ID), cashierID(cashierID), price(0), giftCard(nullptr), timestamp(time(NULL)) {}

size_t Transaction::getID() const {

	return ID;
}

size_t Transaction::getCashierID() const {

	return cashierID;
}

void Transaction::calculatePrice() {

	int productsSize = products.getSize();
	bool useGiftCard = (giftCard != nullptr);
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

void Transaction::addGiftCard(BaseGiftCard* giftCard) {

	this->giftCard = giftCard;
}

Vector<BaseProduct*> Transaction::getProducts() const {

	return products;
}

Vector<size_t> Transaction::getQuantities() const {

	return quantities;
}

std::ostream& Transaction::timestampToStream(std::ostream& os) const {

	tm* timeInfo = localtime(&timestamp);

	os << (timeInfo->tm_mday < 10 ? "0" : "") << timeInfo->tm_mday << "."
		<< (timeInfo->tm_mon + 1 < 10 ? "0" : "") << (timeInfo->tm_mon + 1) << "."
		<< (timeInfo->tm_year + 1900) << " "
		<< (timeInfo->tm_hour < 10 ? "0" : "") << timeInfo->tm_hour << ":"
		<< (timeInfo->tm_min < 10 ? "0" : "") << timeInfo->tm_min << " " 
		<< std::endl;

	return os;
}

