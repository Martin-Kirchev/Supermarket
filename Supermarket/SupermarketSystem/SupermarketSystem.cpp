
#include "SupermarketSystem.h"

void SupermarketSystem::startSystem() {

	bool loop = true;

	while (loop) {

	}

}

void SupermarketSystem::login(const size_t& ID, const my_string& password) {

	int employeesCount = employees.size();

	for (int i = 0; i < employeesCount; i++)
	{
		if (employees[i]->getID() == ID && employees[i]->getPassword() == password) {

			currentWorker = employees[i];
			std::cout << "Logging in successful!" << std::endl;

			return;
		}
	}

	std::cout << "Logging in failed. Employee wasn't found." << std::endl;
}

void SupermarketSystem::logout() {



}

void SupermarketSystem::registr(const my_string& role, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password) {

	if (role == "manager") {

		size_t ID = CountManager::getWorkerIDCounter();
		my_string specialCode = CodeGenerator::generateManagerCode();

		addWorker(new Manager(ID, firstName, lastName, phoneNumber, age, password, specialCode));

		return;
	}

	if (role == "cashier") {

		size_t ID = CountManager::getWorkerIDCounter();

		addWorker(new Cashier(ID, firstName, lastName, phoneNumber, age, password));

		return;
	}

	std::cout << "Logging in successful!" << std::endl;
}

void SupermarketSystem::addWorker(BaseWorker* worker) {

	employees.push_back(worker);
}

void SupermarketSystem::addProduct(BaseProduct* product) {

	products.push_back(product);
}

void SupermarketSystem::addCategory(Category* category) {

	categories.push_back(category);
}

void SupermarketSystem::addGiftCard(BaseGiftCard* giftCard) {

	giftCards.push_back(giftCard);
}

