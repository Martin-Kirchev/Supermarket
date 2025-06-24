

#include "SupermarketSystem.h"

#include <iostream>

int main()
{
	
	SupermarketSystem s = SupermarketSystem();
	//s.startSystem();

	Transaction tr = Transaction(10, 20);

	ReceiptCreator::saveToFile(tr);


}

