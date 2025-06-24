
#include "BaseWorker.h"

BaseWorker::BaseWorker(const size_t& ID, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password) 
	: ID(ID), firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), age(age), password(password) {}

size_t BaseWorker::getID() const {

	return ID;
}

bool BaseWorker::checkPassword(const my_string& password) const {

	return this->password == password;
}

void BaseWorker::printInfo() const {

	std::cout << ID << " : " << firstName << " : " << lastName << " : " << phoneNumber << " : " << age << std::endl;
}