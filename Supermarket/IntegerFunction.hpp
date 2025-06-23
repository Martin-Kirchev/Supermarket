
class IntegerFunction {

public:

	// Number of digits of a number
	static int getDigitsCount(int number) {

		int counter = 0;

		while (number) {

			counter++;
			number /= 10;
		}

		return counter;
	}


	// Power of number
	static int powerOf(const int& number, const size_t& power) {

		int poweredNumber = 1;

		for (size_t i = 0; i < power; i++)
		{
			poweredNumber *= number;
		}

		return poweredNumber;
	}

};