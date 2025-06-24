
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
#include "ReceiptCreator.hpp"

class SupermarketSystem {

public:

	SupermarketSystem() = default;
	SupermarketSystem(const SupermarketSystem& other) = default;
	~SupermarketSystem() = default;

	SupermarketSystem& operator=(const SupermarketSystem& other) = default;

	void startSystem();

	void login(const size_t& ID, const my_string& password);
	void logout();

	void registr(const my_string& role, const my_string& firstName, const my_string& lastName, const my_string& phoneNumber, const size_t& age, const my_string& password);
	void leave();
	
	void list_user_data();
	void list_workers();
	void list_products(const size_t& categoryID);
	void list_feed();
	void list_transactions();
	
	void sell();

	void list_pending();
	void approve(const size_t& cashierID, const my_string& specialCode);
	void decline(const size_t& cashierID, const my_string& specialCode);
	void list_warned_cashiers(const size_t& points);
	void warn_cashier(const size_t& cashierID, const size_t& points);
	void promote_cashier(const size_t& cashierID, const my_string& specialCode);
	void fire_cashier(const size_t& cashierID, const my_string& specialCode);
	void add_category(const my_string& categoryName, const my_string& categoryDescription);
	void delete_category(const size_t& categoryID);
	void add_product(const BaseProduct& product);
	void delete_product(const size_t& productID);
	void load_products(const my_string& filePath);
	void load_gift_cards(const my_string& filePath);

private:

	BaseWorker * currentWorker = nullptr;

	Vector<BaseWorker*> employees;
	Vector<BaseWorker*> pendingEmployees;
	Vector<BaseProduct*> products;
	Vector<Category*> categories;
	Vector<BaseGiftCard*> giftCards;

	BaseWorker* getWorkerByID(const size_t& ID);
	BaseProduct* getProductByIndex(const size_t& ID);
	Category* getCategoryByID(const size_t& ID);
	BaseGiftCard* getGiftCardByCode(const my_string& ID);

	void addWorker(BaseWorker* worker);
	void addProduct(BaseProduct* product);
	void addCategory(Category* category);
	void addGiftCard(BaseGiftCard* giftCard);

};
