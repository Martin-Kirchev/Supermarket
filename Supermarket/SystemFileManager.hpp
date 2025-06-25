
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

		}

		static void save(Vector<BaseWorker*> employees) {

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
				size_t categoryID = input[2].toInteger();
				double price = input[3].toDouble();

				if (type == "by_weight") {

					double kilograms = input[4].toDouble();
					products.push_back(new ProductByWeight(name, categoryID, price, kilograms));

				}
				else if (type == "by_unit") {

					size_t quantity = input[4].toInteger();
					products.push_back(new ProductByUnit(name, categoryID, price, quantity));
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

				MyString type;

				if (products[i]->getType() == ProductType::BY_WEIGHT) {

					type = "by_weight";
					ProductByWeight* p = dynamic_cast<ProductByWeight*>(products[i]);

					file << type << delimiter << products[i]->getName() << delimiter << products[i]->getCategoryID() << delimiter << products[i]->getPrice() << delimiter << p->getKilograms() << endl;

				}
				else if (products[i]->getType() == ProductType::BY_UNIT) {

					type = "by_unit";
					ProductByUnit* p = dynamic_cast<ProductByUnit*>(products[i]);

					file << type << delimiter << products[i]->getName() << delimiter << products[i]->getCategoryID() << delimiter << products[i]->getPrice() << delimiter << p->getQuantity() << endl;
				}
			}

			file.close();
		}
	}

	namespace Categories {

		static MyString categoriesPath = "ResourceFiles/SavedData/Categories.txt";

		static void load(Vector<Category*>& categories) {

		}

		static void save(Vector<Category*>& categories) {

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