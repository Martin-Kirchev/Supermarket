
#include "Cashier.h"


Cashier::Cashier(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password)
	: BaseWorker(ID, firstName, lastName, phoneNumber, age, password) {}

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