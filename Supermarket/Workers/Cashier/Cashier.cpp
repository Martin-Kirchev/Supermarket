
#include "Cashier.h"


Cashier::Cashier(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password)
	: BaseWorker(ID, firstName, lastName, phoneNumber, age, password) {}

Cashier::Cashier(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password, const size_t& numberOfTransactions, const Vector<Warning>& warnings)
	: BaseWorker(ID, firstName, lastName, phoneNumber, age, password), numberOfTransactions(numberOfTransactions), warnings(warnings){}

std::ostream& operator<<(std::ostream& os, const Cashier& cashier) {

	os << toString(cashier.getRole()) << ':' << cashier.getID() << ':' << cashier.getFirstName() << ':' << cashier.getLastName() << ':' << cashier.getPhoneNumber() << ':'
		<< cashier.getAge() << ':' << cashier.getPassword() << ':' << cashier.numberOfTransactions << ':' << cashier.warnings.getSize();

	for (size_t i = 0; i < cashier.warnings.getSize(); i++)
	{
		os << ':' << cashier.warnings[i];
	}

	return os;
}

size_t Cashier::getPointsSum() {

	size_t warningsSize = warnings.getSize();
	size_t pointsSum = 0;

	for (size_t i = 0; i < warningsSize; i++)
	{
		pointsSum += warnings[i].getWarningPoints();
	}

	return pointsSum;
}

void Cashier::addWarning(const Warning& warning) {

	warnings.push_back(warning);
}

WorkerType Cashier::getRole() const {

	return WorkerType::CASHIER;
}