
#pragma once

#include "BaseWorker.h"
#include "Warning.h"
#include "Vector.hpp"

class Cashier : public BaseWorker {

public:

	Cashier() = default;
	Cashier(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password);
	Cashier(const Cashier& other) = default;
	~Cashier() override = default;

	Cashier& operator=(const Cashier& other) = default;

	size_t getPointsSum();
	void addWarning(const Warning& warning);

	WorkerType getRole() const override;

private:

	size_t numberOfTransactions = 0;
	Vector<Warning> warnings;
};
