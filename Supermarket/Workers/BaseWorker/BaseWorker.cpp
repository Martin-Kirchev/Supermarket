
#include "BaseWorker.h"

BaseWorker::BaseWorker(const size_t& ID, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password) 
	: ID(ID), firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), age(age), password(password) {}

size_t BaseWorker::getID() const {

	return ID;
}

my_string BaseWorker::getPassword() const {

	return password;
}