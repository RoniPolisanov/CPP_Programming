#ifndef __CART_H__
#define __CART_H__

#include <iostream>
#include <string>
#include "Item.h"


class Cart
{
protected:
	collection<Item> currentItems;

public:
	float getTotal();
	bool addItem(Item newitem, int quantity, int id, string name, float price);
	bool removeItem(int id, int quantity);
	collection<Item> getItemList();

	Cart();
	~Cart();
};

#endif