
#pragma once

#include "Cashier.h"
#include "Manager.h"
#include "ProductByUnit.h"
#include "ProductByWeight.h"
#include "SingleCategoryGiftCard.h"
#include "MultipleCategoryGiftCard.h"
#include "AllProductsGiftCard.h"

class SupermarketSystem {

public:

	SupermarketSystem() = default;
	SupermarketSystem(const SupermarketSystem& other) = default;
	~SupermarketSystem() = default;

	SupermarketSystem& operator=(const SupermarketSystem& other) = default;

	void startSystem();
	void login(const size_t& ID, const my_string& password);
	void registr(const my_string& role, const my_string firstName, const my_string lastName, const my_string phoneNumber, const size_t age, const my_string password);
	void list_user_data();

private:

	BaseWorker* currentWorker = nullptr;

	my_vector<BaseWorker*> employees;
	my_vector<BaseProduct*> products;
	my_vector<Category> categories;
	my_vector<BaseGiftCard*> giftCards;

};
