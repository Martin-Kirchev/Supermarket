

#include "Utils/Class Helpers/Other/Random.hpp"

#include <iostream>

int main()
{
	
	my_string str = "TESTSTR ";

	str.push(Random::randomDigit());
	str.push(Random::randomUpper());
	str.push(Random::randomDigit());
	str.push(Random::randomUpper());

	std::cout << str;

}

