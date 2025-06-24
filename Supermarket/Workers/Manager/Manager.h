
#pragma once

#include "BaseWorker.h"
#include "Random.hpp"

class Manager : public BaseWorker {

public:

	Manager() = default;
	Manager(const size_t& ID, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password, const MyString& specialCode);
	Manager(const Manager& other) = default;
	~Manager() override = default;

	Manager& operator=(const Manager& other) = default;

	bool checkCode(const MyString& specialCode);

	WorkerType getRole() const override;

private:

	MyString specialCode;

};
