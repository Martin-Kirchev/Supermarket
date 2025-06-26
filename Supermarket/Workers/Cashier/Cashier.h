
#pragma once

#include "BaseWorker.h"
#include "Warning.h"
#include "Vector.hpp"

class Cashier : public BaseWorker {

public:

	Cashier() = default;
	Cashier(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password);
	Cashier(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password, const size_t& numberOfTransactions, const Vector<Warning>& warnings);
	Cashier(const Cashier& other) = default;
	~Cashier() override = default;

	Cashier& operator=(const Cashier& other) = default;
	friend std::ostream& operator<<(std::ostream& os, const Cashier& cashier);

	size_t getPointsSum();
	void addWarning(const Warning& warning);
	void addTransaction();

	WorkerType getRole() const override;

private:

	size_t numberOfTransactions = 0;
	Vector<Warning> warnings;
};
