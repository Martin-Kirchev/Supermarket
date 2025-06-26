
#pragma once

#include <iostream>
#include <fstream>
#include "Transaction.h"
#include "IntegerFunction.hpp"

namespace ReceiptCreator {

	static MyString ReceiptPath = "ResourceFiles/Receipts/";

	static void saveToFile(const Transaction& transaction) {

		MyString transactionID;
		transactionID.push(transaction.getID());

		Vector<BaseProduct*> products = transaction.getProducts();
		size_t productsSize = products.getSize();

		Vector<double> quantities = transaction.getQuantities();

		MyString cashierID;
		cashierID.push(transaction.getCashierID());

		MyString price;
		price.push(IntegerFunction::round(transaction.getCurrentPrice()));

		MyString path = ReceiptPath + "receipt_";
		path.push(transactionID);
		path.push(".txt");

		ofstream file(path.c_str());

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
			file << quantities[i] << "*" << products[i]->getPrice() << " - " << quantities[i] * products[i]->getPrice() << " BGN" << endl;
			file << std::endl;
			file << "###" << std::endl;
			file << std::endl;
		}

		if (transaction.giftCardIsUsed()) {

			file << std::endl;
			file << "A gift card was used." << std::endl;
			file << std::endl;
		}

		file << "TOTAL: " << price << " BGN" << std::endl;

		file.close();
	}

};