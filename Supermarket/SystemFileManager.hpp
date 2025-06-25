
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
	}

	namespace PendingEmployees {

		static MyString pendingEmployeesPath = "ResourceFiles/SavedData/PendingEmployees.txt";

		static void load(Vector<BaseWorker*>& pendingEmployees) {

		}

		static void save(Vector<BaseWorker*>& pendingEmployees) {

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
				MyString type = toString(products[i]->getType());

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

		}

		static void save(Vector<BaseGiftCard*>& giftCards) {

		}
	}

};