
#pragma once

#include "my_string.h"
#include "Random.hpp"
#include "CountManager.hpp"

class CodeGenerator {

public:

	static my_string generateManagerCode() {

		my_string code = "";
		
		code.push(Random::randomDigit());
		code.push(Random::randomUpper());
		code.push(Random::randomUpper());
		code.push(Random::randomDigit());
		code.push(Random::randomDigit());
		code.push(Random::randomDigit());
		code.push(Random::randomLower());

		return code;
	}

	static my_string generateGiftCardCode() {

		my_string code = "";

		code.push(Random::randomDigit());
		code.push(Random::randomUpper());
		code.push(CountManager::getGiftCardCounter());
		code.push(Random::randomUpper());
		code.push(Random::randomDigit());

		return code;
	}

};