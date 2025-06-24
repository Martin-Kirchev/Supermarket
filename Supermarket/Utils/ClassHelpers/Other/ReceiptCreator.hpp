
#pragma once

#include <iostream>
#include <fstream>
#include "Transaction.h"
#include "IntegerFunction.hpp"

class ReceiptCreator {

	static void saveToFile(const Transaction& transaction) {

		my_string transactionID;
		transactionID.pushInteger(transaction.getID());

		my_string cashierID;
		cashierID.pushInteger(transaction.getCashierID());

		my_string time = transaction.timestampToString();

		my_string price;
		price.pushInteger(IntegerFunction::round(transaction.getCurrentPrice()));

		ofstream file("Receipts/receipt_");

		file << "RECEIPT" << std::endl;
		file << std::endl;
		file << "TRANSACTION_ID: " << transactionID << std::endl;
		file << std::endl;
		file << "CASHIER_ID:" << cashierID << std::endl;
		file << std::endl;
		file << time << std::endl;
		file << std::endl;
		file << "------------------------------" << std::endl;
		file << std::endl;

		for (size_t i = 0; i < productsSize; i++)
		{

				//  <PRODUCT_NAME>
				//
				//	<QTY>*<PRICE> -<TOTAL_PRICE>
				//
				//	###

		}

		file << "TOTAL: " << price << "BGN" << std::endl;

		file.close();
	}

};