
#include "Manager.h"

Manager::Manager(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password, const MyString& specialCode)
	: BaseWorker(ID, firstName, lastName, phoneNumber, age, password), specialCode(specialCode) {}

bool Manager::checkCode(const MyString& specialCode) {

	return this->specialCode == specialCode;
}

WorkerType Manager::getRole() const {

	return WorkerType::MANAGER;
}