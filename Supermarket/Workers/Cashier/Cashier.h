
#pragma once

#include "BaseWorker.h"
#include "Warning.h"
#include "Vector.hpp"

class Cashier : public BaseWorker {

public:

	Cashier() = default;
	Cashier(const size_t& ID, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password);
	Cashier(const Cashier& other) = default;
	~Cashier() override = default;

	Cashier& operator=(const Cashier& other) = default;

	WorkerType getRole() const override;

private:

	size_t numberOfTransactions = 0;
	Vector<Warning> warnings;
};
