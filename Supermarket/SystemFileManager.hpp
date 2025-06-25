
#pragma once

#include <fstream>

#include "Vector.hpp"
#include "MyString.h"
#include "Cashier.h"
#include "Manager.h"
#include "ProductByUnit.h"
#include "ProductByWeight.h"
#include "SingleCategoryGiftCard.h"
#include "MultipleCategoryGiftCard.h"
#include "AllProductsGiftCard.h"
#include "CountManager.hpp"
#include "TypeManager.hpp"
#include "CodeGenerator.hpp"

namespace SystemFileManager {

	namespace Employees {

		static MyString employeesPath = "ResourceFiles/SavedData/Employees.txt";

		static void load(Vector<BaseWorker*>& employees) {

			ifstream file(employeesPath.c_str());

			if (!file.is_open())
				return;

			MyString inputLine;

			while (getline(file, inputLine)) {

				Vector<MyString> input = inputLine.split(':');

				MyString role = input[0];
				size_t ID = input[1].toInteger();
				MyString firstName = input[2];
				MyString lastName = input[3];
				MyString phoneNumber = input[4];
				size_t age = input[5].toInteger();
				MyString password = input[6];

				if (role == "MANAGER") {

					MyString managerFilePath = MyString("ResourceFiles/SpecialCodes/");
					managerFilePath.push(ID);
					managerFilePath.push("_special_code.txt");

					ifstream managerFile(managerFilePath.c_str());

					MyString specialCode;
					getline(managerFile, specialCode);

					employees.push_back(new Manager(ID, firstName, lastName, phoneNumber, age, password, specialCode));

					managerFile.close();
				}
				else if (role == "CASHIER") {

					size_t numberOfTransactions = input[7].toInteger();
					size_t numberOfWarnings = input[8].toInteger();

					Vector<Warning> warnings;

					for (size_t i = 1; i <= numberOfWarnings * 3; i += 3)
					{
						MyString sender = input[8 + i];
						MyString description = input[8 + i + 1];
						WarningLevel warningLevel = warningLevelFromString(input[8 + i + 2]);

						warnings.push_back(Warning(sender, description, warningLevel));
					}

					employees.push_back(new Cashier(ID, firstName, lastName, phoneNumber, age, password, numberOfTransactions, warnings));
				}
			}

			file.close();
		}

		static void save(Vector<BaseWorker*> employees) {

			ofstream file(employeesPath.c_str());

			if (!file.is_open())
				return;

			for (size_t i = 0; i < employees.getSize(); i++)
			{
				if (employees[i]->getRole() == WorkerType::CASHIER) {

					Cashier* c = dynamic_cast<Cashier*>(employees[i]);

					file << *c << endl;
				}
				else if (employees[i]->getRole() == WorkerType::MANAGER) {

					Manager* m = dynamic_cast<Manager*>(employees[i]);

					file << *m << endl;
				}
			}

			file.close();
		}


		static void createManagerCodeFile(const size_t& ID, const MyString& code) {

			MyString managerFilePath = MyString("ResourceFiles/SpecialCodes/");
			managerFilePath.push(ID);
			managerFilePath.push("_special_code.txt");

			ofstream managerFile(managerFilePath.c_str());

			managerFile << code;

			managerFile.close();
		}

	}

	namespace PendingEmployees {

		static MyString pendingEmployeesPath = "ResourceFiles/SavedData/PendingEmployees.txt";

		static void load(Vector<BaseWorker*>& pendingEmployees) {

			ifstream file(pendingEmployeesPath.c_str());

			if (!file.is_open())
				return;

			MyString inputLine;

			while (getline(file, inputLine)) {

				Vector<MyString> input = inputLine.split(':');

				size_t ID = input[0].toInteger();
				MyString firstName = input[1];
				MyString lastName = input[2];
				MyString phoneNumber = input[3];
				size_t age = input[4].toInteger();
				MyString password = input[5];

				pendingEmployees.push_back(new BaseWorker(ID, firstName, lastName, phoneNumber, age, password));
			}

			file.close();
		}

		static void save(Vector<BaseWorker*>& pendingEmployees) {

			ofstream file(pendingEmployeesPath.c_str());

			if (!file.is_open())
				return;

			for (size_t i = 0; i < pendingEmployees.getSize(); i++) {

				file << pendingEmployees[i]->getID() << ':' << pendingEmployees[i]->getFirstName() << ':' << pendingEmployees[i]->getLastName() << ':'
					<< pendingEmployees[i]->getPhoneNumber() << ':' << pendingEmployees[i]->getAge() << ':' << pendingEmployees[i]->getPassword() << endl;
			}

			file.close();
		}
	}

	namespace Products {

		static MyString productsPath = "ResourceFiles/SavedData/Products.txt";

		static void load(Vector<BaseProduct*>& products) {

			ifstream file(productsPath.c_str());

			if (!file.is_open())
				return;

			MyString inputLine;

			while (getline(file, inputLine)) {

				Vector<MyString> input = inputLine.split(':');

				MyString type = input[0];
				MyString name = input[1];
				MyString categoryName = input[2];
				double price = input[3].toDouble();

				if (type == "BY_WEIGHT") {

					double kilograms = input[4].toDouble();
					products.push_back(new ProductByWeight(name, categoryName, price, kilograms));

				}
				else if (type == "BY_UNIT") {

					size_t quantity = input[4].toInteger();
					products.push_back(new ProductByUnit(name, categoryName, price, quantity));
				}
			}

			file.close();
		}

		static void save(Vector<BaseProduct*>& products) {

			ofstream file(productsPath.c_str());

			if (!file.is_open())
				return;

			MyString inputLine;
			char delimiter = ':';

			for (size_t i = 0; i < products.getSize(); i++)
			{
				if (products[i]->getType() == ProductType::BY_WEIGHT) {

					ProductByWeight* p = dynamic_cast<ProductByWeight*>(products[i]);
					file << *p << endl;

				}
				else if (products[i]->getType() == ProductType::BY_UNIT) {

					ProductByUnit* p = dynamic_cast<ProductByUnit*>(products[i]);
					file << *p << endl;
				}
			}

			file.close();
		}
	}

	namespace Categories {

		static MyString categoriesPath = "ResourceFiles/SavedData/Categories.txt";

		static void load(Vector<Category*>& categories) {

			ifstream file(categoriesPath.c_str());

			if (!file.is_open())
				return;

			MyString inputLine;

			while (getline(file, inputLine)) {

				Vector<MyString> input = inputLine.split(':');

				MyString name = input[0];
				MyString description = input[1];

				categories.push_back(new Category(name, description));
			}

			file.close();
		}

		static void save(Vector<Category*>& categories) {

			ofstream file(categoriesPath.c_str());

			if (!file.is_open())
				return;

			MyString inputLine;
			char delimiter = ':';

			for (size_t i = 0; i < categories.getSize(); i++) {

				file << categories[i]->getName() << delimiter << categories[i]->getDescription() << endl;
			}

			file.close();
		}
	}

	namespace GiftCards {

		static MyString giftCardsPath = "ResourceFiles/SavedData/GiftCards.txt";

		static void load(Vector<BaseGiftCard*>& giftCards) {

			ifstream file(giftCardsPath.c_str());

			if (!file.is_open())
				return;

			MyString inputLine;

			while (getline(file, inputLine)) {

				Vector<MyString> input = inputLine.split(':');

				MyString type = input[0];
				MyString code = input[1];

				if (type == "SINGLE_CATEGORY") {

					MyString categoryName = input[2];
					size_t percentage = input[3].toInteger();
					giftCards.push_back(new SingleCategoryGiftCard(code, percentage, categoryName));

				}
				else if (type == "MULTIPLE_CATEGORY") {

					size_t categoriesSize = input[2].toInteger();
					Vector<MyString> categories;

					for (size_t i = 1; i <= categoriesSize; i++)
					{
						categories.push_back(input[2 + i]);
					}

					size_t percentage = input[3 + categoriesSize].toInteger();

					giftCards.push_back(new MultipleCategoryGiftCard(code, percentage, categories));

				}
				else if (type == "ALL_PRODUCTS") {

					size_t percentage = input[2].toInteger();
					giftCards.push_back(new AllProductsGiftCard(code, percentage));
				}
			}

			file.close();
		}

		static void save(Vector<BaseGiftCard*>& giftCards) {

			ofstream file(giftCardsPath.c_str());

			if (!file.is_open())
				return;

			MyString inputLine;

			for (size_t i = 0; i < giftCards.getSize(); i++) {

				if (giftCards[i]->getType() == GiftCardType::SINGLE_CATEGORY) {

					SingleCategoryGiftCard* g = dynamic_cast<SingleCategoryGiftCard*>(giftCards[i]);
					file << *g << endl;

				}
				else if (giftCards[i]->getType() == GiftCardType::MULTIPLE_CATEGORY) {

					MultipleCategoryGiftCard* g = dynamic_cast<MultipleCategoryGiftCard*>(giftCards[i]);
					file << *g << endl;
				}
				else if (giftCards[i]->getType() == GiftCardType::ALL_PRODUCTS) {

					AllProductsGiftCard* g = dynamic_cast<AllProductsGiftCard*>(giftCards[i]);
					file << *g << endl;
				}
			}

			file.close();
		}
	}
	namespace Feed {

		static MyString feedPath = "ResourceFiles/Feed/feed.txt";

		static void add(const MyString& input) {

			ofstream file(feedPath.c_str(), ios::app);

			if (!file.is_open())
				return;

			file << input << endl;
		}

		 static void print() {

			ifstream file(feedPath.c_str());

			MyString inputLine;

			while (getline(file, inputLine)) {

				cout << inputLine << endl;
			}
		}
	}
};