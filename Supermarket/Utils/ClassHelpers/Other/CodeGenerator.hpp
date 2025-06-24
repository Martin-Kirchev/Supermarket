
#pragma once

#include "MyString.h"
#include "Random.hpp"
#include "CountManager.hpp"

class CodeGenerator {

public:

	static MyString generateManagerCode() {

		MyString code = "";
		
		code.push(Random::randomDigit());
		code.push(Random::randomUpper());
		code.push(Random::randomUpper());
		code.push(Random::randomDigit());
		code.push(Random::randomDigit());
		code.push(Random::randomDigit());
		code.push(Random::randomLower());

		return code;
	}

	static MyString generateGiftCardCode() {

		MyString code = "";

		code.push(Random::randomDigit());
		code.push(Random::randomUpper());
		code.push(CountManager::getGiftCardCounter());
		code.push(Random::randomUpper());
		code.push(Random::randomDigit());

		return code;
	}

};