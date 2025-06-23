
#include "Manager.h"

Manager::Manager(const size_t ID, const my_string firstName, const my_string lastName, const my_string phoneNumber, const size_t age, const my_string password)
	: BaseWorker(ID, firstName, lastName, phoneNumber, age, password) {

	this->specialCode = generateSpecialCode();
}

my_string Manager::generateSpecialCode() {

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