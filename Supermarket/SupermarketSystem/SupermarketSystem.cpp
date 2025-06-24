
#include "SupermarketSystem.h"

void SupermarketSystem::startSystem() {

	bool loop = true;

	while (loop) {

	}

}

void SupermarketSystem::login(const size_t& ID, const my_string& password) {

	int employeesCount = employees.getSize();

	for (int i = 0; i < employeesCount; i++)
	{
		if (employees[i]->getID() == ID && employees[i]->checkPassword(password)) {

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

void SupermarketSystem::leave()
{
}

void SupermarketSystem::list_user_data()
{
}

void SupermarketSystem::list_workers()
{
}

void SupermarketSystem::list_products(const size_t& categoryID)
{
}

void SupermarketSystem::list_feed()
{
}

void SupermarketSystem::list_transactions()
{
}

void SupermarketSystem::sell() {

	Transaction transaction = Transaction(CountManager::getCategoryCounter(), currentWorker->getID());

	my_string command;

	while (true) {

		std::cout << "Products:" << std::endl;

		int productsSize = products.getSize();

		for (size_t i = 0; i < productsSize; i++)
		{
			std::cout << i << ". ";
			products[i]->print();
		}

		std::cout << "Transaction ID: " << CountManager::getTransactionsCounter() << std::endl;

		transaction.calculatePrice();
		std::cout << "Price: " << transaction.getCurrentPrice() << std::endl;


		std::cout << "Enter product ID to sell. Enter END to end the transaction:" << std::endl;
		std::cin >> command;

		int index = command.toNumber();

		if (index == -1)
			continue;

		if (command == "END") 
			break;
		
		size_t quantity;
		std::cout << "Enter quantity:" << std::endl;
		std::cin >> quantity;

		transaction.addProduct(products[index], quantity);

		//change quantity

		std::cout << "---------" << std::endl;
	}

	char answer;
	std::cout << "Add voucher : (Y / N) ?" << std::endl;
	std::cin >> answer;

	switch (answer) {

	case 'Y' :

		my_string giftCardCode;
		std::cout << "Enter voucher:" << std::endl;
		std::cin >> giftCardCode;

		transaction.addGiftCard(getGiftCardByCode(giftCardCode));

		break;
	}

	transaction.calculatePrice();
	std::cout << "Total: " << transaction.getCurrentPrice() << std::endl;

	ReceiptCreator::saveToFile(transaction);
}

void SupermarketSystem::list_pending() {

	int pendingWorkersSize = pendingEmployees.getSize();

	for (size_t i = 0; i < pendingWorkersSize; i++)
	{
		pendingEmployees[i]->printInfo();
	}
}

void SupermarketSystem::approve(const size_t& cashierID, const my_string& specialCode) {

	//if(currentWorker.)

	int pendingWorkersSize = pendingEmployees.getSize();

	for (size_t i = 0; i < pendingWorkersSize; i++)
	{
		if (pendingEmployees[i]->getID() == cashierID) {

			employees.push_back(pendingEmployees[i]);
			pendingEmployees.remove(i);

			break;
		}
	}

}

void SupermarketSystem::decline(const size_t& cashierID, const my_string& specialCode)
{
}

void SupermarketSystem::list_warned_cashiers(const size_t& points)
{
}

void SupermarketSystem::warn_cashier(const size_t& cashierID, const size_t& points)
{
}

void SupermarketSystem::promote_cashier(const size_t& cashierID, const my_string& specialCode)
{
}

void SupermarketSystem::fire_cashier(const size_t& cashierID, const my_string& specialCode)
{
}

void SupermarketSystem::add_category(const my_string& categoryName, const my_string& categoryDescription)
{
}

void SupermarketSystem::delete_category(const size_t& categoryID)
{
}

void SupermarketSystem::add_product(const BaseProduct& product)
{
}

void SupermarketSystem::delete_product(const size_t& productID)
{
}

void SupermarketSystem::load_products(const my_string& filePath)
{
}

void SupermarketSystem::load_gift_cards(const my_string& filePath)
{
}

BaseWorker* SupermarketSystem::getWorkerByID(const size_t& ID) {

	int workersSize = employees.getSize();

	for (size_t i = 0; i < workersSize; i++)
	{
		if (ID == employees[i]->getID()) {

			return employees[i];
		}
	}

	return nullptr;
}

BaseProduct* SupermarketSystem::getProductByIndex(const size_t& index) {

	return products[index];
}

//Category* SupermarketSystem::getCategoryByID(const size_t& ID) {
//
//}

BaseGiftCard* SupermarketSystem::getGiftCardByCode(const my_string& code) {

	int giftCardSize = giftCards.getSize();

	for (size_t i = 0; i < giftCardSize; i++)
	{
		if (giftCards[i]->checkCode(code)) {

			return giftCards[i];
		}
	}

	return nullptr;
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




