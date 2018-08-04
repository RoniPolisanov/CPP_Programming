#ifndef __WAREHOUSEMANAGER_H__
#define __WAREHOUSEMANAGER_H__

#include <iostream>
#include <string>

using namespace std;

class WarehouseManager
{
private:

public:
	collection<Item> availableItems();
	Item getItemByID(int id);
	bool writeNewOrder(Cart new);
	collection<Cart> getAllOrders();
	WarehouseManager();
	~WarehouseManager();
};

#endif