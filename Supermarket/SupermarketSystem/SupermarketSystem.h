
#pragma once

#include "Cashier.h"
#include "Manager.h"
#include "ProductByUnit.h"
#include "ProductByWeight.h"
#include "SingleCategoryGiftCard.h"
#include "MultipleCategoryGiftCard.h"
#include "AllProductsGiftCard.h"
#include "Transaction.h"
#include "CountManager.hpp"
#include "CodeGenerator.hpp"

class SupermarketSystem {

public:

	SupermarketSystem() = default;
	SupermarketSystem(const SupermarketSystem& other) = default;
	~SupermarketSystem() = default;

	SupermarketSystem& operator=(const SupermarketSystem& other) = default;

	void startSystem();

	void login(const size_t& ID, const my_string& password);
	void logout();

	void registr(const my_string& role, const my_string& firstName, const my_string& lastName, const my_string &phoneNumber, const size_t& age, const my_string& password);
	//void leave();
	//
	//void list_user_data();
	//void list_workers();
	//void list_products(const size_t& category_id);
	//void list_feed();
	//void list_transactions();
	//
	void sell();

private:

	BaseWorker* currentWorker = nullptr;

	my_vector<BaseWorker*> employees;
	my_vector<BaseProduct*> products;
	my_vector<Category*> categories;
	my_vector<BaseGiftCard*> giftCards;

	BaseWorker* getWorkerByID(const size_t& ID);
	BaseProduct* getProductByIndex(const size_t& ID);
	Category* getCategoryByID(const size_t& ID);
	BaseGiftCard* getGiftCardByCode(const my_string& ID);

	void addWorker(BaseWorker* worker);
	void addProduct(BaseProduct* product);
	void addCategory(Category* category);
	void addGiftCard(BaseGiftCard* giftCard);

};
