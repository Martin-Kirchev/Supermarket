
#pragma once

namespace CountManager {

	static size_t workerIDCounter = 100;
	static size_t categoryCounter = 0;
	static size_t giftCardCounter = 10000;
	static size_t transactionsCounter = 0;
	
	static void increaseWorkerID() {

		workerIDCounter++;
	}

	static void increaseCategory() {

		categoryCounter++;
	}

	static void increaseGiftCard() {

		giftCardCounter++;
	}

	static void increaseTransactions() {

		
		transactionsCounter++;
	}

	static size_t getWorkerIDCounter() {

		return workerIDCounter;
	}

	static size_t getCategoryCounter() {

		return categoryCounter;
	}

	static size_t getGiftCardCounter() {

		return giftCardCounter;
	}

	static size_t getTransactionsCounter() {

		return transactionsCounter;
	}

};