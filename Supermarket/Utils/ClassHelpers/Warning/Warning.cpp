
#include "Warning.h"

Warning::Warning(const my_string& sender, const my_string& description, const WarningLevel& warningLevel)
	: sender(sender), description(description), warningLevel(warningLevel) {}

size_t Warning::getWarningPoints() {

	return static_cast<size_t> (warningLevel);
}