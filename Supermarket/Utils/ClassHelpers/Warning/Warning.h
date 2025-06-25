
#pragma once

#include "MyString.h"
#include "WarningLevel.hpp"

class Warning {

public:

	Warning() = default;
	Warning(const MyString& sender, const MyString& description, const WarningLevel& warningLevel);
	Warning(const Warning& other) = default;
	~Warning() = default;

	Warning& operator=(const Warning& other) = default;
	friend std::ostream& operator<<(std::ostream& os, const Warning& warning);

	size_t getWarningPoints();

private:

	MyString sender;
	MyString description;
	WarningLevel warningLevel = WarningLevel::DEFAULT;

};