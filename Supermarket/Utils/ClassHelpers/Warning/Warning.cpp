
#include "Warning.h"

Warning::Warning(const MyString& sender, const MyString& description, const WarningLevel& warningLevel)
	: sender(sender), description(description), warningLevel(warningLevel) {}

std::ostream& operator<<(std::ostream& os, const Warning& warning) {

	os << warning.sender << ':' << warning.description << ':' << toString(warning.warningLevel);

	return os;
}

size_t Warning::getWarningPoints() {

	return static_cast<size_t> (warningLevel);
}