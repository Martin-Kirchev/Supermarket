
#include "Warning.h"

Warning::Warning(const MyString& sender, const MyString& description, const WarningLevel& warningLevel)
	: sender(sender), description(description), warningLevel(warningLevel) {}

size_t Warning::getWarningPoints() {

	return static_cast<size_t> (warningLevel);
}