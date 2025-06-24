
#include "Cashier.h"


Cashier::Cashier(const size_t& ID, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password)
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