
#include "Warning.h"

Warning::Warning(const my_string sender, const my_string description, const WarningLevel warningLevel)
	: sender(sender), description(description), warningLevel(warningLevel) {}