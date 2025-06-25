
#pragma once

#include <fstream>

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

	SupermarketSystem();
	SupermarketSystem(const SupermarketSystem& other) = default;
	~SupermarketSystem();

	SupermarketSystem& operator=(const SupermarketSystem& other) = default;

	bool userIsManager();
	bool userIsCashier();
	bool userIsLoggedIn();

	void login(const size_t& ID, const MyString& password);
	void logout();

	void registr(const MyString& role, const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const size_t& age, const MyString& password);
	void leave();
	
	void list_user_data();
	void list_workers();
	void list_products(const size_t& categoryID);
	void list_feed();
	void list_transactions();
	
	void sell();

	void list_pending();
	void approve(const size_t& cashierID, const MyString& specialCode);
	void decline(const size_t& cashierID, const MyString& specialCode);
	void list_warned_cashiers(const size_t& points);
	void warn_cashier(const size_t& cashierID, const size_t& points);
	void promote_cashier(const size_t& cashierID, const MyString& specialCode);
	void fire_cashier(const size_t& cashierID, const MyString& specialCode);
	void add_category(const MyString& categoryName, const MyString& categoryDescription);
	void delete_category(const size_t& categoryID);
	void add_product(const ProductType& productType);
	void delete_product(const size_t& productID);
	void load_products(const MyString& filePath);
	void load_gift_cards(const MyString& filePath);

private:

	BaseWorker * currentWorker = new Manager(10, "Ivan", "Ivanov", "+345", 20, "password", "code");

	Vector<BaseWorker*> employees;
	Vector<BaseWorker*> pendingEmployees;
	Vector<BaseProduct*> products;
	Vector<Category*> categories;
	Vector<BaseGiftCard*> giftCards;

	BaseWorker* getWorkerByID(const size_t& ID);
	BaseWorker* getCashierByID(const size_t& ID);
	BaseProduct* getProductByIndex(const size_t& ID);
	Category* getCategoryByID(const size_t& categoryID);
	Category* getCategoryByName(const MyString& categoryID);
	BaseGiftCard* getGiftCardByCode(const MyString& ID);

	void loadSupermarketDataToFile();
	void saveSupermarketDataToFile();

	void addWorker(BaseWorker* worker);
	void addProduct(BaseProduct* product);
	void addCategory(Category* category);
	void addGiftCard(BaseGiftCard* giftCard);

};
