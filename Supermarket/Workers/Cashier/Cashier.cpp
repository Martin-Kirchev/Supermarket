
#include "Cashier.h"


Cashier::Cashier(const size_t& ID, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password)
	: BaseWorker(ID, firstName, lastName, phoneNumber, age, password) {}

WorkerType Cashier::getRole() const {

	return WorkerType::CASHIER;
}