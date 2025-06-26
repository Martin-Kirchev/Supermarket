
#include "Transaction.h"


Transaction::Transaction(const size_t& ID, const size_t& cashierID) : ID(ID), cashierID(cashierID), price(0), giftCard(nullptr), timestamp(time(NULL)) {}

size_t Transaction::getID() const {

	return ID;
}

size_t Transaction::getCashierID() const {

	return cashierID;
}

void Transaction::useGiftCard() {

	if (giftCard == nullptr) {

		cout << endl;
		cout << "Gift card was not found." << endl;
		return;
	}

	size_t productsSize = products.getSize();
	double tempPrice = 0;

	for (size_t i = 0; i < productsSize; i++)
	{
		double currentProductPrice = 0;

		if (products[i]->getType() == ProductType::BY_UNIT) {

			currentProductPrice += (products[i]->getPrice() * quantities[i]);
		}

		if (products[i]->getType() == ProductType::BY_WEIGHT) {

			currentProductPrice += (products[i]->getPrice()) * (quantities[i] / 1000.0);
		}

		if (giftCard->getType() == GiftCardType::SINGLE_CATEGORY) {

			SingleCategoryGiftCard* g = dynamic_cast<SingleCategoryGiftCard*>(giftCard);

			if (products[i]->getCategoryName() == g->getCategoryName())
				currentProductPrice -= (currentProductPrice * (giftCard->getPercentage() / 100.0));

		}
		else if (giftCard->getType() == GiftCardType::MULTIPLE_CATEGORY) {

			MultipleCategoryGiftCard* g = dynamic_cast<MultipleCategoryGiftCard*>(giftCard);

			if (g->checkForCategory(products[i]->getCategoryName()))
				currentProductPrice -= (currentProductPrice * (g->getPercentage() / 100.0));

		}
		else if (giftCard->getType() == GiftCardType::ALL_PRODUCTS) {

			currentProductPrice -= (currentProductPrice * (giftCard->getPercentage() / 100.0));

		}

		tempPrice += currentProductPrice;
	}

	price = tempPrice;

	cout << giftCard->getPercentage() << "% applied! ";
}

void Transaction::calculatePrice() {

	size_t productsSize = products.getSize();
	double tempPrice = 0;

	for (size_t i = 0; i < productsSize; i++)
	{

		if (products[i]->getType() == ProductType::BY_UNIT) {

			tempPrice += (products[i]->getPrice() * quantities[i]);
			continue;
		}

		if (products[i]->getType() == ProductType::BY_WEIGHT) {

			tempPrice += (products[i]->getPrice() * quantities[i]);
			continue;
		}
	}

	price = tempPrice;
}

double Transaction::getCurrentPrice() const {

	return price;
}

void Transaction::addProduct(BaseProduct* product, const double& quantity) {

	this->products.push_back(product);
	this->quantities.push_back(quantity);
}

void Transaction::addGiftCard(BaseGiftCard* giftCard) {

	this->giftCard = giftCard;
}

bool Transaction::giftCardIsUsed() const {
	return this->giftCard != nullptr;
}

Vector<BaseProduct*> Transaction::getProducts() const {

	return products;
}

Vector<double> Transaction::getQuantities() const {

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

void Transaction::printInfo() {

	cout << "ID: " << ID << endl;
	cout << "Cashier ID: " << cashierID << endl;

	std::cout << "Products:\n";
	for (size_t i = 0; i < products.getSize(); i++) {

		cout << i + 1 << ". " << products[i]->getName() << " x" << quantities[i] << endl;
	}

	std::cout << "Gift Card: ";
	if (giftCard != nullptr) {

		cout << toString(giftCard->getType()) << endl;
	}
	else {

		cout << "None" << endl;
	}

	cout << "Total Price: " << price << endl;

	std::cout << "Time: ";
	timestampToStream(cout);
}

