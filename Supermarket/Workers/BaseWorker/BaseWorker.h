
#pragma once

#include "my_string.h"
#include "TypeManager.hpp"

class BaseWorker {

public:

	BaseWorker() = default;
	BaseWorker(const size_t& ID, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password);
	BaseWorker(const BaseWorker& other) = default;
	virtual ~BaseWorker() = default;

	virtual BaseWorker& operator=(const BaseWorker& other) = default;

	size_t getID() const;
	bool checkPassword(const my_string& password) const;

	virtual WorkerType getRole() const = 0;

	void printInfo() const;

private:

	size_t ID = 0;
	my_string firstName;
	my_string lastName;
	my_string phoneNumber;
	size_t age = 0;
	my_string password;

};
