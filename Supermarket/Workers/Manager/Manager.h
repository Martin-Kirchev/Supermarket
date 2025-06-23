
#pragma once

#include "BaseWorker.h"
#include "Random.hpp"

class Manager : public BaseWorker {

public:

	Manager() = default;
	Manager(const size_t& ID, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password);
	Manager(const Manager& other) = default;
	~Manager() override = default;

	Manager& operator=(const Manager& other) = default;

private:

	my_string specialCode;

	my_string generateSpecialCode();

};
