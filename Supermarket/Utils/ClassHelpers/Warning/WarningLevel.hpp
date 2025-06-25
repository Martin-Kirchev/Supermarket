
#pragma once

enum class WarningLevel {

	DEFAULT = 0,
	LOW = 100,
	MEDIUM = 200,
	HIGH = 300

};

inline const char* toString(WarningLevel level) {

	switch (level) {

	case WarningLevel::DEFAULT: return "DEFAULT";
	case WarningLevel::LOW:     return "LOW";
	case WarningLevel::MEDIUM:  return "MEDIUM";
	case WarningLevel::HIGH:    return "HIGH";

	}
}

inline WarningLevel warningLevelFromString(const MyString& level) {

	if (level == "DEFAULT") return WarningLevel::DEFAULT;
	if (level == "LOW") return WarningLevel::LOW;
	if (level == "MEDIUM") return WarningLevel::MEDIUM;
	if (level == "HIGH") return WarningLevel::HIGH;

}