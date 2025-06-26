
#pragma once

namespace CountManager {

	static size_t workerIDCounter = 100;
	static size_t giftCardCounter = 10000;
	static size_t transactionsCounter = 1;

	static size_t getWorkerIDCounter() {

		return workerIDCounter++;
	}

	static size_t peekWorkerIDCounter() {

		return workerIDCounter;
	}

	static size_t getGiftCardCounter() {

		return giftCardCounter++;
	}

	static size_t peekGiftCardCounter() {

		return giftCardCounter;
	}

	static size_t getTransactionsCounter() {

		return transactionsCounter++;
	}

	static size_t peekTransactionsCounter() {

		return transactionsCounter;
	}

};