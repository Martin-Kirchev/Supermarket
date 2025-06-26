
#include "SupermarketSystem.h"

SupermarketSystem::SupermarketSystem() {

	loadSupermarketDataFromFile();
}

SupermarketSystem::~SupermarketSystem() {

	saveSupermarketDataToFile();
}

void SupermarketSystem::login(const size_t& ID, const MyString& password) {

	size_t employeesCount = employees.getSize();

	for (size_t i = 0; i < employeesCount; i++)
	{
		if (employees[i]->getID() == ID && employees[i]->checkPassword(password)) {

			currentWorker = employees[i];

			cout << "User " << currentWorker->getFirstName() + " " + currentWorker->getLastName()
				<< " with ID:" << currentWorker->getID()
				<< " was logged into the system."
				<< endl;

			return;
		}
	}

	cout << "User wasn't found." << endl;
}

void SupermarketSystem::logout() {

	currentWorker = nullptr;

	cout << "Logged out." << endl;
}

void SupermarketSystem::registr(const MyString& role, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password) {

	if (role == "manager") {

		size_t ID = CountManager::getWorkerIDCounter();
		MyString specialCode = CodeGenerator::generateManagerCode();

		addWorker(new Manager(ID, firstName, lastName, phoneNumber, age, password, specialCode));
		cout << "Manager was created with file " << currentWorker->getID() << "_special_code.txt." << endl;

		return;
	}

	if (role == "cashier") {

		size_t ID = CountManager::getWorkerIDCounter();

		addPendingWorker(new BaseWorker(ID, firstName, lastName, phoneNumber, age, password));
		cout << "Cashier registration pending approval from a manager." << endl;

		return;
	}

	cout << "Wrong role type." << endl;
}

void SupermarketSystem::leave() {

	size_t employeesCount = employees.getSize();

	for (size_t i = 0; i < employeesCount; i++)
	{

		if (currentWorker->getID() == employees[i]->getID()) {

			employees.remove(i);
			currentWorker == nullptr;

			break;
		}
	}

	cout << "Leaving work was successful." << endl;
}

void SupermarketSystem::list_user_data() {

	cout << "Worker info:" << endl;
	currentWorker->printInfo();
}

void SupermarketSystem::list_workers() {

	cout << "All workers info:" << endl;

	size_t employeesCount = employees.getSize();
	for (size_t i = 0; i < employeesCount; i++)
	{
		employees[i]->printInfo();
		cout << endl;
	}
}

void SupermarketSystem::list_products() {

	cout << "All products info:" << endl;

	size_t productsCount = products.getSize();
	for (size_t i = 0; i < productsCount; i++)
	{
		products[i]->printInfo();
		cout << endl;
	}

}

void SupermarketSystem::list_products(const MyString& categoryName) {

	cout << "All " << categoryName << "products info :" << endl;

	size_t productsCount = products.getSize();
	for (size_t i = 0; i < productsCount; i++)
	{
		if (products[i]->getCategoryName() == categoryName) {

			products[i]->printInfo();
			cout << endl;
		}
	}
}

void SupermarketSystem::list_feed() {

	SystemFileManager::Feed::print();
}

void SupermarketSystem::list_transactions() {

	SystemFileManager::Receipt::print(CountManager::peekTransactionsCounter());
}

void SupermarketSystem::sell() {

	Transaction transaction = Transaction(CountManager::getTransactionsCounter(), currentWorker->getID());

	while (true) {

		MyString command;

		cout << "Products:" << endl;

		size_t productsSize = products.getSize();

		for (size_t i = 0; i < productsSize; i++)
		{
			cout << i + 1 << ". ";
			products[i]->printInfo();
		}

		cout << endl;
		cout << "Transaction ID: " << transaction.getID() << endl;

		transaction.calculatePrice();
		cout << "Price: " << transaction.getCurrentPrice() << " BGN" << endl;
		cout << endl;

		cout << "Enter product ID to sell. Enter END to end the transaction:" << endl;
		getline(cin, command);

		if (command == "END")
			break;

		int index = command.toInteger();

		if (index == -1)
			continue;

		cout << "Enter quantity:" << endl;
		getline(cin, command);

		double quantity = command.toDouble();

		if (index == -1)
			continue;

		if (products[index - 1]->isPossibleToBuy(quantity)) {

			products[index - 1]->removeFromQuantity(quantity);
			transaction.addProduct(products[index - 1], quantity);
		}
		else {

			cout << endl;
			cout << "There is not enough quantity of this product for you to buy." << endl;
		}

		cout << endl;
		cout << "------------------" << endl;
		cout << endl;
	}

	transaction.calculatePrice();

	MyString answer;
	cout << "Add voucher : (Y / N) ?" << endl;
	getline(cin, answer);

	switch (*answer.c_str()) {

	case 'Y':

		MyString giftCardCode;
		cout << "Enter voucher:" << endl;
		getline(cin, giftCardCode);

		transaction.addGiftCard(getGiftCardByCode(giftCardCode));
		transaction.useGiftCard();

		break;
	}

	cout << endl;
	cout << "Transaction complete!" << endl;
	cout << endl;
	cout << "Total: " << transaction.getCurrentPrice() << " BGN" << endl;

	ReceiptCreator::saveToFile(transaction);
	cout << "Receipt saved as : receipt_" << transaction.getID() << ".txt" << endl;
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

			employees.push_back(new Cashier(pendingEmployees[i]->getID(), pendingEmployees[i]->getFirstName(), pendingEmployees[i]->getLastName(),
				pendingEmployees[i]->getPhoneNumber(), pendingEmployees[i]->getAge(), pendingEmployees[i]->getPassword()));

			pendingEmployees.remove(i);

			cout << "Cashier was approved." << endl;
			break;
		}
	}

	cout << "Pending cashier was not found." << endl;
}

void SupermarketSystem::decline(const size_t& cashierID, const MyString& specialCode) {

	Manager* manager = dynamic_cast<Manager*>(currentWorker);

	if (!manager->checkCode(specialCode))
		return;

	size_t pendingWorkersSize = pendingEmployees.getSize();

	for (size_t i = 0; i < pendingWorkersSize; i++) {

		if (pendingEmployees[i]->getID() == cashierID) {

			pendingEmployees.remove(i);

			cout << "Cashier was declined." << endl;
			break;
		}
	}

	cout << "Pending cashier was not found." << endl;
}

void SupermarketSystem::list_warned_cashiers(const size_t& points) {

	cout << "List of warning cashiers with more than " << points << " warning points:" << endl;

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

	if (cashier == nullptr) {

		cout << "Cashier was not found." << endl;
		return;
	}

	MyString description;
	cout << "Enter warning description:" << endl;
	getline(cin, description);

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

		cout << "Invalid amount of points!" << endl;
		return;
	}

	Warning warning = Warning(sender, description, warningLevel);

	Cashier* c = dynamic_cast<Cashier*>(cashier);
	c->addWarning(warning);

	cout << "Cashier was warned." << endl;
}

void SupermarketSystem::promote_cashier(const size_t& cashierID, const MyString& specialCode) {

	Manager* manager = dynamic_cast<Manager*>(currentWorker);

	if (!manager->checkCode(specialCode))
		return;

	size_t workersSize = employees.getSize();

	for (size_t i = 0; i < workersSize; i++) {

		if (employees[i]->getID() != cashierID)
			continue;

		if (employees[i]->getRole() != WorkerType::CASHIER) {

			cout << "Employee is not a cashier!" << endl;
			break;
		}

		MyString specialCode = CodeGenerator::generateManagerCode();
		addWorker(new Manager(employees[i]->getID(), employees[i]->getFirstName(), employees[i]->getLastName(), employees[i]->getPhoneNumber(), employees[i]->getAge(), employees[i]->getPassword(), specialCode));

		employees.remove(i);

		cout << "Cashier was promoted to a manager." << endl;
		return;
	}

	cout << "Cashier was not found." << endl;
}

void SupermarketSystem::fire_cashier(const size_t& cashierID, const MyString& specialCode) {

	Manager* manager = dynamic_cast<Manager*>(currentWorker);

	if (!manager->checkCode(specialCode))
		return;

	size_t workersSize = employees.getSize();

	for (size_t i = 0; i < workersSize; i++) {

		if (employees[i]->getID() != cashierID)
			continue;

		if (employees[i]->getRole() != WorkerType::CASHIER) {

			cout << "Employee is not a cashier!" << endl;
			break;
		}

		employees.remove(i);

		cout << "Cashier was fired." << endl;
		return;
	}

	cout << "Cashier was not found." << endl;
}

void SupermarketSystem::add_category(const MyString& categoryName, const MyString& categoryDescription) {

	if (getCategoryByName(categoryName) != nullptr) {

		cout << "This category already exists!" << endl;
		return;
	}

	addCategory(new Category(categoryName, categoryDescription));
	cout << "Category was added!" << endl;
}

void SupermarketSystem::delete_category(const MyString& categoryName) {

	size_t categoriesSize = categories.getSize();

	for (size_t i = 0; i < categoriesSize; i++) {

		if (categories[i]->getName() == categoryName) {

			categories.remove(i);

			cout << "Category was removed" << endl;
			return;
		}
	}

	cout << "Category was not found." << endl;
}

void SupermarketSystem::add_product(const ProductType& productType) {

	MyString productName;
	getline(cin, productName);

	if (getCategoryByName(productName) != nullptr) {

		cout << "This product already exists!" << endl;
		return;
	}

	MyString categoryName;
	getline(cin, categoryName);

	if (getCategoryByName(categoryName) == nullptr) {

		cout << "Category was not found." << endl;
		return;
	}
		
	double price;
	getline(cin, price);

	if (productType == ProductType::BY_UNIT) {

		size_t quantity;
		getline(cin, quantity);

		addProduct(new ProductByUnit(productName, categoryName, price, quantity));

		cout << "Product by unit was added." << endl;
		return;
	}

	if (productType == ProductType::BY_WEIGHT) {

		double kilograms;
		getline(cin, kilograms);

		addProduct(new ProductByWeight(productName, categoryName, price, kilograms));

		cout << "Product by weight was added." << endl;
		return;
	}

	cout << "Incorrect product type." << endl;
}

void SupermarketSystem::delete_product(const MyString& productName) {

	size_t productsSize = products.getSize();

	for (size_t i = 0; i < productsSize; i++) {

		if (products[i]->getName() == productName) {

			products.remove(i);

			cout << "Product was removed" << endl;
			return;
		}
	}

	cout << "Product was not found." << endl;
}

//void SupermarketSystem::load_products(const MyString& filePath) {
//
//}
//
//void SupermarketSystem::load_gift_cards(const MyString& filePath) {
//
//}

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

Category* SupermarketSystem::getCategoryByID(const size_t& categoryID) {

	size_t categoriesSize = categories.getSize();

	for (size_t i = 0; i < categoriesSize; i++) {

		if (i == categoryID)
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
		if (giftCards[i]->checkCode(code))
			return giftCards[i];

	}

	return nullptr;
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

void SupermarketSystem::addPendingWorker(BaseWorker* pendingWorker) {

	pendingEmployees.push_back(pendingWorker);
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




