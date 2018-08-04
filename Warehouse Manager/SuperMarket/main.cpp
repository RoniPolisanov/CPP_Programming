#include <iostream>
#include <string>
#include "Item.h"
using namespace std;


int main()
{
	Item AmitHagever();
	Item Amit(12, 2, 44.4, "Schwarz");
	DiscountItem ItzhakNudler(50.00, 20, 30, 40.00, "SUMO");
	cout << ItzhakNudler.discountedPrice() << endl;
	//Print Item List
	//To Add Item To Cart
	//Remove Item From Cart
	//Print Full Cart
	//Make Purchase
	//Exit From Current Order Without Purchasing
	//Show All The Purchases
	//Exit

}