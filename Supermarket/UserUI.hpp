
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
			SystemFileManager::Feed::add(inputLine);

			Vector<MyString> input = inputLine.split(' ');

			MyString command = input[0];

			if (command == "END") {

				break;
			}

			if (command == "/help") {

				printListOfCommands();
				continue;
			}

			if (command == "register") {

				MyString role = input[1];
				MyString firstName = input[2];
				MyString lastName = input[3];
				MyString phoneNumber = input[4];
				size_t age = input[5].toInteger();
				MyString password = input[6];

				system.registr(role, firstName, lastName, phoneNumber, age, password);
				continue;
			}

			if (command == "login") {

				if (system.userIsLoggedIn()) {

					cout << "You are logged in!" << endl;
					continue;
				}

				size_t ID = input[1].toInteger();
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

				if (input.getSize() > 1) {

					MyString categoryName = input[1];
					system.list_products(categoryName);

					continue;
				}

				system.list_products();
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

			if (command == "sell") {

				if (!system.userIsCashier()) {

					cout << "You are not a cashier!" << endl;
					continue;
				}

				system.sell();
				continue;
			}

			if (!system.userIsManager()) {

				cout << "You are not a manager!" << endl;
				continue;
			}

			if (command == "list_pending") {

				system.list_pending();
				continue;
			}

			if (command == "approve") {

				size_t cashierID = input[1].toInteger();;
				MyString specialCode = input[2];

				system.approve(cashierID, specialCode);
				continue;
			}

			if (command == "decline") {

				size_t cashierID = input[1].toInteger();;
				MyString specialCode = input[2];

				system.decline(cashierID, specialCode);
				continue;
			}

			if (command == "list_warned_cashiers") {

				size_t points = input[1].toInteger();

				system.list_warned_cashiers(points);
				continue;
			}

			if (command == "warn_cashier") {

				size_t cashierID = input[1].toInteger();
				size_t points = input[2].toInteger();

				system.warn_cashier(cashierID, points);
				continue;
			}

			if (command == "promote_cashier") {

				size_t cashierID = input[1].toInteger();;
				MyString specialCode = input[2];

				system.promote_cashier(cashierID, specialCode);
				continue;
			}

			if (command == "fire_cashier") {

				size_t cashierID = input[1].toInteger();
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

				MyString categoryName = input[1];

				system.delete_category(categoryName);
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

				MyString productName = input[1];

				system.delete_product(productName);
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

private:

	void printListOfCommands() {

		ifstream file("ResourceFiles/SavedData/ListOfCommands.txt");

		if (!file.is_open()) {

			return;
		}

		MyString inputLine;
		while (getline(file, inputLine)) {

			cout << inputLine << endl;
		}

		file.close();
	}

};