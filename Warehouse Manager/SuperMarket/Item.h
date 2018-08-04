#ifndef __ITEM_H__
#define __ITEM_H__

#include <iostream>
#include <string>

using namespace std;


class Item
{
protected:
	int quantity,
		id;
	float price;
	string name;

public:
	inline const float& getPrice(){ return price; }
	inline const int& getQuantity() { return quantity; }
	inline const int& getId() { return id; }
	inline const string& getName() { return name; }

	void setQuantity(int& quantity_){ quantity = quantity_; }
	void setPrice(float& price_) { price = price_; }
	void setId(int& id_) {id = id_; }
	void setName(string& name_) { name = name_; }

	Item() : name("None"), id(0), price(0.00), quantity(0){};
	Item(int id_, int quantity_, float price_, string name_);
	~Item();
};

Item::Item(int id_, int quantity_, float price_, string name_)
{
	cout << "enter items constructor" << endl;
	id = id_;
	quantity = quantity_;
	price = price_;
	name = name_;
}

class DiscountItem : public Item
{
private:
	float discountValue;

public:
	float discountedPrice() { return (discountValue*price) / 100; }
	inline const float getPrice() { return price; }	//using class Item Price (the original price)
	DiscountItem() : discountValue(0){};
	DiscountItem(float discountValue_, int id_, int quantity_, float price_, string name_);
	~DiscountItem();
};

DiscountItem::DiscountItem(float discountValue_, int id_, int quantity_, float price_, string name_)
{
	cout << "enter deep DiscountItem constructor" << endl;
	discountValue = discountValue_;
	Item::Item(id_, quantity_, price_, name_);
}

#endif
