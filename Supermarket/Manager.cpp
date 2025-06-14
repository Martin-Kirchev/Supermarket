
#include "Manager.h"

Manager::Manager(const size_t ID, const my_string firstName, const my_string lastName, const my_string phoneNumber, const size_t age, const my_string password, const my_string specialCode, const my_string specialPassword)
	: BaseWorker(ID, firstName, lastName, phoneNumber, age, password), specialCode(specialCode), specialPassword(specialPassword) {}
