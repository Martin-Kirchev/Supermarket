

#include "UserUI.hpp"

#include <iostream>

int main()
{

	//Vector<BaseProduct*> products;
	//
	//products.push_back(new ProductByUnit("Water", 1, 3.50, 100));
	//products.push_back(new ProductByWeight("Banana", 2, 3.50, 100.11));
	//
	//SystemFileManager::Products::save(products);

	UserUI ui;
	ui.startSystem();

	MyString input;
	getline(std::cin, input);


}

