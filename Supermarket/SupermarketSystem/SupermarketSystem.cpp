
#include "SupermarketSystem.h"



void SupermarketSystem::startSystem() {

	bool loop = true;

	while (loop) {

	}

}

void SupermarketSystem::login(const size_t& ID, const my_string& password) {

	int employeesCount = employees.size();

	for (size_t i = 0; i < employeesCount; i++)
	{
		if (employees[i]->getID() == ID && employees[i]->getPassword() == password) {

			currentWorker = employees[i];
			std::cout << "Logging in successful!" << std::endl;

			return;
		}
	}

	std::cout << "Logging in failed. Employee wasn't found." << std::endl;
}


void SupermarketSystem::registr(const my_string& role, const my_string firstName, const my_string lastName, const my_string phoneNumber, const size_t age, const my_string password) {



}

