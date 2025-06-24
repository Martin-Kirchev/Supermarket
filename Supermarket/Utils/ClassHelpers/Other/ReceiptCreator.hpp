
#pragma once

#include <iostream>
#include <fstream>
#include "Transaction.h"
#include "IntegerFunction.hpp"

class ReceiptCreator {

public:

	static void saveToFile(const Transaction& transaction) {

		my_string transactionID;
		transactionID.pushInteger(transaction.getID());

		Vector<BaseProduct*> products = transaction.getProducts();
		size_t productsSize = products.getSize();

		Vector<size_t> quantities = transaction.getQuantities();

		my_string cashierID;
		cashierID.pushInteger(transaction.getCashierID());

		my_string price;
		price.pushInteger(IntegerFunction::round(transaction.getCurrentPrice()));

		std::ofstream file("ResourceFiles/Receipts/receipt_10.txt");

		if (!file.is_open()) {
			return;
		}

		file << "RECEIPT" << std::endl;
		file << std::endl;
		file << "TRANSACTION_ID: " << transactionID << std::endl;
		file << std::endl;
		file << "CASHIER_ID: " << cashierID << std::endl;
		file << std::endl;
		transaction.timestampToStream(file);
		file << std::endl;
		file << "------------------------------" << std::endl;
		file << std::endl;

		for (size_t i = 0; i < productsSize; i++)
		{
			file << products[i]->getName() << std::endl;
			file << std::endl;
			file << quantities[i] << "*" << products[i]->getPrice() << " - " << quantities[i] * products[i]->getPrice() << std::endl;
			file << std::endl;
			file << "###" << std::endl;
			file << std::endl;
		}

		file << "TOTAL: " << price << "BGN" << std::endl;

		file.close();
	}

};