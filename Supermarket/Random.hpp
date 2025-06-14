
#pragma once

#include <cstdlib>

class Random {

public:

	// Random number between '0' and '9'
	static char randomDigit() {

		return '0' + rand() % 10;
	}


	// 'A' to 'Z'
	static char randomUpper() {

		return 'A' + rand() % 26;  
	}

	// 'a' to 'z'
	static char randomLower() {

		return 'a' + rand() % 26;
	}

};