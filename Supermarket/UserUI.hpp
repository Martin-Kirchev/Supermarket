
#pragma once

#include "SupermarketSystem.h"

using std::cout;
using std::cin;

class UserUI {

    SupermarketSystem system;

public:

    void startSystem() {

		cout << "Welcome to FMI Supermarket Management System 2024-2025!" << endl;
		cout << "Please choose an action:" << endl;
		cout << "(You can type /help for a list of options)" << endl;

		while (true) {

			cout << endl;

			MyString inputLine;
			getline(cin, inputLine);

			Vector<MyString> input = inputLine.split(' ');

			MyString command = input[0];

			if (command == "END") {

				break;
			}

			if (command == "/help") {

				printListOfCommands();
				continue;
			}

			if (command == "login" && !system.userIsLoggedIn()) {

				size_t ID = input[1].toNumber();
				MyString password = input[2];

				system.login(ID, password);
				continue;
			}

			if (!system.userIsLoggedIn()) {
			
				cout << "You need to login first!" << endl;
				continue;
			}

			if (command == "logout") {

				system.logout();
				continue;
			}

			if (command == "register") {

				MyString role = input[1];
				MyString firstName = input[2];
				MyString lastName = input[3];
				MyString phoneNumber = input[4];
				size_t age = input[5].toNumber();
				MyString password = input[6];


				system.registr(role, firstName, lastName, phoneNumber, age, password);
				continue;
			}

			if (command == "leave") {

				system.leave();
				continue;
			}

			if (command == "list_user_data") {

				system.list_user_data();
				continue;
			}

			if (command == "list_workers") {

				system.list_workers();
				continue;
			}

			if (command == "list_products") {

				size_t categoryID = input[1].toNumber();;

				system.list_products(categoryID);
				continue;
			}

			if (command == "list_feed") {

				system.list_feed();
				continue;
			}

			if (command == "list_transactions") {

				system.list_transactions();
				continue;
			}

			if (system.userIsCashier())
				continue;

			if (command == "sell" && system.userIsCashier()) {

				system.sell();
				continue;
			}

			if (!system.userIsManager())
				continue;

			if (command == "list_pending") {

				system.list_pending();
				continue;
			}

			if (command == "approve") {

				size_t cashierID = input[1].toNumber();;
				MyString specialCode = input[2];

				system.approve(cashierID, specialCode);
				continue;
			}

			if (command == "decline") {

				size_t cashierID = input[1].toNumber();;
				MyString specialCode = input[2];

				system.decline(cashierID, specialCode);
				continue;
			}

			if (command == "list_warned_cashiers") {

				size_t points = input[1].toNumber();

				system.list_warned_cashiers(points);
				continue;
			}

			if (command == "warn_cashier") {

				size_t cashierID = input[1].toNumber();
				size_t points = input[2].toNumber();

				system.warn_cashier(cashierID, points);
				continue;
			}

			if (command == "promote_cashier") {

				size_t cashierID = input[1].toNumber();;
				MyString specialCode = input[2];

				system.promote_cashier(cashierID, specialCode);
				continue;
			}

			if (command == "fire_cashier") {

				size_t cashierID = input[1].toNumber();
				MyString specialCode = input[2];

				system.fire_cashier(cashierID, specialCode);
				continue;
			}

			if (command == "add_category") {

				MyString categoryName = input[1];
				MyString categoryDescription = input[2];

				system.add_category(categoryName, categoryDescription);
				continue;
			}

			if (command == "delete_category") {

				size_t categoryID = input[1].toNumber();

				system.delete_category(categoryID);
				continue;
			}

			if (command == "add_product") {

				MyString productType = input[1];

				if (productType == "product_by_unit")
					system.add_product(ProductType::BY_UNIT);

				if (productType == "product_by_weight")
					system.add_product(ProductType::BY_WEIGHT);

				continue;
			}

			if (command == "delete_product") {

				size_t productID = input[1].toNumber();

				system.delete_product(productID);
				continue;
			}

			if (command == "load_products") {

				MyString filePath = input[1];

				system.load_products(filePath);
				continue;
			}

			if (command == "load_gift_cards") {

				MyString filePath = input[1];

				system.load_gift_cards(filePath);
				continue;
			}

		}
    }

	void printListOfCommands() {

		ifstream file("ResourceFiles/SavedData/ListOfCommands.txt");

		if (!file.is_open()) {

			return;
		}

		cout << endl;
		cout << "List of commands: " << endl;

		MyString inputLine;
		while (getline(file, inputLine)) {

			cout << inputLine << endl;
		}
	}
    
};