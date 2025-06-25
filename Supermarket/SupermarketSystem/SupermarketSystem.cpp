
#include "SupermarketSystem.h"

SupermarketSystem::SupermarketSystem() {

	loadSupermarketDataFromFile();
}

SupermarketSystem::~SupermarketSystem() {

	saveSupermarketDataToFile();
}

bool SupermarketSystem::userIsManager()
{
	return currentWorker->getRole() == WorkerType::MANAGER;
}

bool SupermarketSystem::userIsCashier()
{
	return currentWorker->getRole() == WorkerType::CASHIER;
}

bool SupermarketSystem::userIsLoggedIn()
{
	return currentWorker != nullptr;
}

void SupermarketSystem::login(const size_t& ID, const MyString& password) {

	size_t employeesCount = employees.getSize();

	for (size_t i = 0; i < employeesCount; i++)
	{
		if (employees[i]->getID() == ID && employees[i]->checkPassword(password)) {

			currentWorker = employees[i];

			std::cout 
				<< "User " << currentWorker->getFirstName() + " " + currentWorker->getLastName()
				<< " with ID: " << currentWorker->getID() 
				<< " has been logged into the system!" 
				<< std::endl;

			return;
		}
	}

	std::cout << "User wasn't found." << std::endl;
}

void SupermarketSystem::logout() {

	currentWorker = nullptr;
}

void SupermarketSystem::registr(const MyString& role, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password) {

	if (role == "manager") {

		size_t ID = CountManager::getWorkerIDCounter();
		MyString specialCode = CodeGenerator::generateManagerCode();

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

	MyString command;

	while (true) {

		std::cout << "Products:" << std::endl;

		size_t productsSize = products.getSize();

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

		int index = command.toInteger();

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

	case 'Y':

		MyString giftCardCode;
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

	size_t pendingWorkersSize = pendingEmployees.getSize();

	for (size_t i = 0; i < pendingWorkersSize; i++)
	{
		pendingEmployees[i]->printInfo();
	}
}

void SupermarketSystem::approve(const size_t& cashierID, const MyString& specialCode) {

	Manager* manager = dynamic_cast<Manager*>(currentWorker);

	if (!manager->checkCode(specialCode))
		return;

	size_t pendingWorkersSize = pendingEmployees.getSize();

	for (size_t i = 0; i < pendingWorkersSize; i++) {

		if (pendingEmployees[i]->getID() == cashierID) {

			employees.push_back(pendingEmployees[i]);
			pendingEmployees.remove(i);

			break;
		}
	}

}

void SupermarketSystem::decline(const size_t& cashierID, const MyString& specialCode) {

	Manager* manager = dynamic_cast<Manager*>(currentWorker);

	if (!manager->checkCode(specialCode))
		return;

	size_t pendingWorkersSize = pendingEmployees.getSize();

	for (size_t i = 0; i < pendingWorkersSize; i++) {

		if (pendingEmployees[i]->getID() == cashierID) {

			pendingEmployees.remove(i);
			break;
		}
	}

}

void SupermarketSystem::list_warned_cashiers(const size_t& points) {

	size_t workersSize = employees.getSize();

	for (size_t i = 0; i < workersSize; i++) {

		if (employees[i]->getRole() != WorkerType::CASHIER)
			continue;

		Cashier* cashier = dynamic_cast<Cashier*>(employees[i]);

		if (cashier->getPointsSum() > points)
			employees[i]->printInfo();

	}
}

void SupermarketSystem::warn_cashier(const size_t& cashierID, const size_t& points) {

	BaseWorker* cashier = getCashierByID(cashierID);

	if (cashier == nullptr)
		return;

	MyString description;
	std::cout << "Enter warning description:" << std::endl;
	std::cin >> description;

	MyString sender = currentWorker->getFirstName() + " " + currentWorker->getLastName();
	WarningLevel warningLevel;

	if (points == 100)
	{
		warningLevel = WarningLevel::LOW;
	}
	else if (points == 200) {

		warningLevel = WarningLevel::MEDIUM;
	}
	else if (points == 300) {

		warningLevel = WarningLevel::HIGH;
	}
	else {

		return;
	}

	Warning warning = Warning(sender, description, warningLevel);

	Cashier* c = dynamic_cast<Cashier*>(cashier);
	c->addWarning(warning);
}

void SupermarketSystem::promote_cashier(const size_t& cashierID, const MyString& specialCode) {

	Manager* manager = dynamic_cast<Manager*>(currentWorker);

	if (!manager->checkCode(specialCode))
		return;


	size_t workersSize = employees.getSize();

	for (size_t i = 0; i < workersSize; i++) {

		if (employees[i]->getID() != cashierID)
			continue;

		if (employees[i]->getRole() != WorkerType::CASHIER)
			break;

		MyString specialCode = CodeGenerator::generateManagerCode();
		addWorker(new Manager(employees[i]->getID(), employees[i]->getFirstName(), employees[i]->getLastName(), employees[i]->getPhoneNumber(), employees[i]->getAge(), employees[i]->getPassword(), specialCode));

		employees.remove(i);
		break;
	}
}

void SupermarketSystem::fire_cashier(const size_t& cashierID, const MyString& specialCode) {

	Manager* manager = dynamic_cast<Manager*>(currentWorker);

	if (!manager->checkCode(specialCode))
		return;

	size_t workersSize = employees.getSize();

	for (size_t i = 0; i < workersSize; i++) {

		if (employees[i]->getID() != cashierID)
			continue;

		if (employees[i]->getRole() != WorkerType::CASHIER)
			break;

		employees.remove(i);
		break;
	}
}

void SupermarketSystem::add_category(const MyString& categoryName, const MyString& categoryDescription) {

	if (getCategoryByName(categoryName) != nullptr)
		return;

	addCategory(new Category(CountManager::categoryCounter, categoryName, categoryDescription));
}

void SupermarketSystem::delete_category(const size_t& categoryID) {

	size_t categoriesSize = categories.getSize();

	for (size_t i = 0; i < categoriesSize; i++) {

		if (categories[i]->getID() == categoryID) {

			categories.remove(i);
			break;
		}
	}
}

void SupermarketSystem::add_product(const ProductType& productType) {

	MyString name;
	cin >> name;

	MyString categoryName;
	cin >> categoryName;

	if (categoryName == nullptr)
		return;

	double price;
	cin >> price;


	if (productType == ProductType::BY_UNIT) {

		size_t quantity;
		cin >> quantity;

		addProduct(new ProductByUnit(name, getCategoryByName(categoryName)->getID(), price, quantity));
		return;
	}

	if (productType == ProductType::BY_WEIGHT) {

		double kilograms;
		cin >> kilograms;

		addProduct(new ProductByWeight(name, getCategoryByName(categoryName)->getID(), price, kilograms));
		return;
	}
}

void SupermarketSystem::delete_product(const size_t& productID) {

	if (products.getSize() <= productID)
		return;

	products.remove(productID);
}

void SupermarketSystem::load_products(const MyString& filePath) {

}

void SupermarketSystem::load_gift_cards(const MyString& filePath) {

}

BaseWorker* SupermarketSystem::getWorkerByID(const size_t& cashierID) {

	size_t workersSize = employees.getSize();

	for (size_t i = 0; i < workersSize; i++)
	{
		if (cashierID == employees[i]->getID()) {

			return employees[i];
		}
	}

	return nullptr;
}

BaseWorker* SupermarketSystem::getCashierByID(const size_t& ID) {

	size_t workersSize = employees.getSize();

	for (size_t i = 0; i < workersSize; i++) {
		if (ID == employees[i]->getID()) {

			if (employees[i]->getRole() == WorkerType::CASHIER)
				return employees[i];

			break;
		}
	}

	return nullptr;
}

BaseProduct* SupermarketSystem::getProductByIndex(const size_t& index) {

	if (products.getSize() <= index)
		return nullptr;

	return products[index];
}

Category* SupermarketSystem::getCategoryByID(const size_t& categoryID) {

	size_t categoriesSize = categories.getSize();

	for (size_t i = 0; i < categoriesSize; i++) {

		if (categories[i]->getID() == categoryID)
			return categories[i];

	}

	return nullptr;
}

Category* SupermarketSystem::getCategoryByName(const MyString& categoryName) {

	size_t categoriesSize = categories.getSize();

	for (size_t i = 0; i < categoriesSize; i++) {

		if (categories[i]->getName() == categoryName)
			return categories[i];

	}

	return nullptr;
}

BaseGiftCard* SupermarketSystem::getGiftCardByCode(const MyString& code) {

	size_t giftCardSize = giftCards.getSize();

	for (size_t i = 0; i < giftCardSize; i++)
	{
		if (giftCards[i]->checkCode(code)) {

			return giftCards[i];
		}
	}

	return nullptr;
}

void SupermarketSystem::loadSupermarketDataFromFile() {

	SystemFileManager::Employees::load(employees);
	SystemFileManager::PendingEmployees::load(pendingEmployees);
	SystemFileManager::Products::load(products);
	SystemFileManager::Categories::load(categories);
	SystemFileManager::GiftCards::load(giftCards);
}

void SupermarketSystem::saveSupermarketDataToFile() {

	SystemFileManager::Employees::save(employees);
	SystemFileManager::PendingEmployees::save(pendingEmployees);
	SystemFileManager::Products::save(products);
	SystemFileManager::Categories::save(categories);
	SystemFileManager::GiftCards::save(giftCards);
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




