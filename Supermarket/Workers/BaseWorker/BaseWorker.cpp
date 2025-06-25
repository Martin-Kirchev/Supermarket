
#include "BaseWorker.h"

BaseWorker::BaseWorker(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password)
	: ID(ID), firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), age(age), password(password) {
}

size_t BaseWorker::getID() const {

	return ID;
}

MyString BaseWorker::getFirstName() const
{
	return firstName;
}

MyString BaseWorker::getLastName() const
{
	return lastName;
}

MyString BaseWorker::getPhoneNumber() const
{
	return phoneNumber;
}

size_t BaseWorker::getAge() const
{
	return age;
}

MyString BaseWorker::getPassword() const
{
	return password;
}

bool BaseWorker::checkPassword(const MyString& password) const {

	return this->password == password;
}

WorkerType BaseWorker::getRole() const {

	return WorkerType::BASE;
}

void BaseWorker::printInfo() const {

	cout << "Position: " << toString(getRole()) << endl
		<< "ID: " << ID << endl
		<< "First Name: " << firstName << endl
		<< "Last Name: " << lastName << endl
		<< "Phone Number: " << phoneNumber << endl
		<< "Age: " << age << endl
		<< "Password: " << password << endl;
}