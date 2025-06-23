
#pragma once

#include "my_string.h"

class BaseWorker {

public:

	BaseWorker() = default;
	BaseWorker(const size_t& ID, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password);
	BaseWorker(const BaseWorker& other) = default;
	virtual ~BaseWorker() = 0;

	virtual BaseWorker& operator=(const BaseWorker& other) = default;

	size_t getID() const;
	my_string getPassword() const;

private:

	size_t ID = 0;
	my_string firstName;
	my_string lastName;
	my_string phoneNumber;
	size_t age = 0;
	my_string password;

};
