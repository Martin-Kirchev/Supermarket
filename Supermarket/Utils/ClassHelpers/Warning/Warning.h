
#pragma once

#include "my_string.h"
#include "WarningLevel.hpp"

class Warning {

public:

	Warning() = default;
	Warning(const my_string& sender, const my_string& description, const WarningLevel& warningLevel);
	Warning(const Warning& other) = default;
	~Warning() = default;

	Warning& operator=(const Warning& other) = default;

	size_t getWarningPoints();

private:

	my_string sender;
	my_string description;
	WarningLevel warningLevel = WarningLevel::DEFAULT;

};