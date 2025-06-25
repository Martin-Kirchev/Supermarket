
#pragma once

#include "MyString.h"
#include "TypeManager.hpp"

class BaseWorker {

public:

	BaseWorker() = default;
	BaseWorker(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password);
	BaseWorker(const BaseWorker& other) = default;
	virtual ~BaseWorker() = default;

	virtual BaseWorker& operator=(const BaseWorker& other) = default;

	size_t getID() const;
	MyString getFirstName() const;
	MyString getLastName() const;
	MyString getPhoneNumber() const;
	size_t getAge() const;
	MyString getPassword() const;
	bool checkPassword(const MyString& password) const;

	virtual WorkerType getRole() const;

	void printInfo() const;

private:

	size_t ID = 0;
	MyString firstName;
	MyString lastName;
	MyString phoneNumber;
	size_t age = 0;
	MyString password;

};
