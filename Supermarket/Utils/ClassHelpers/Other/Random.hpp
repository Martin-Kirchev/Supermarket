
#pragma once

#include <cstdlib>

class Random {

public:

	// Random number between '0' and '9'
	static char randomDigit() {

		resetRandom();

		return '0' + rand() % 10;
	}


	// 'A' to 'Z'
	static char randomUpper() {

		resetRandom();

		return 'A' + rand() % 26;  
	}

	// 'a' to 'z'
	static char randomLower() {

		resetRandom();

		return 'a' + rand() % 26;
	}

private:

	static void resetRandom() {

		static bool used = false;

		if (!used) {

			srand(time(NULL));
			used = true;
		}
	}

};