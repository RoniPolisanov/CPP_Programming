#include <iostream>
#include <string>
#include <fstream>
#include "Cards.h"


using namespace std;

const char* colors[] = { "Red", "Green", "Blue", "Purple", "Orange" };
const char* defaultCard = "Pimp";

//C'tors
Card::Card(char* name, int val, char* color)				//Constructor
{
	cout << "Card Constructor Activated." << endl;
	setName(name);
	setVal(val);
	setColor(color);
	cout << "Constructor quit." << endl;
}

Card::Card() : val(0), color(Red)							//Constructor
{
	cout << "Cards Constructor Activated." << endl;
	setName(0);
	cout << "Constructor quit." << endl;
}

Card::~Card()												//Destructor
{
	cout << "Cards Destructor Activated." << endl;
	if (name!= NULL) delete[] name;
	cout << "Destructor quit" << endl;
}

//Getters
const char* Card::getName() const { return this->name; };	//getting card's name
const int Card::getVal() const { return this->val; };		//getting the value of the card
const Color Card::getColor() const { return this->color; };	//getting pplayers color

//Setters
void Card::setName(char* name)								//Setting cards name
{
	if (name != NULL)
	{
		this->name = new char[strlen(name) +1];
		if (this->name == NULL) { cerr << "Error allocation memory" << endl; return; }
		strcpy(this->name, name);
		return;
	}
	else
	{
		this->name = new char[strlen(defaultCard) + 1];
		if (this->name == NULL) { cerr << "Error allocation memory" << endl; return; }
		strcpy(this->name, defaultCard);
	}
}

void Card::setVal(int val){ this->val = val; }

void Card::setColor(char *token)							//Setting cards color
{
	if (strcmp(token, "Red") == 0){ Color c = Red; this->color = Red; return; }
	if (strcmp(token, "Green") == 0) { Color c = Green; this->color = Green; return; }
	if (strcmp(token, "Blue") == 0)  { Color c = Blue; this->color = Blue; return; }
	if (strcmp(token, "Purple") == 0){ Color c = Purple; this->color = Purple; return; }
	if (strcmp(token, "Orange") == 0){ Color c = Orange; this->color = Orange; return; }
	cerr << "Error Set color" << endl;
}

//Other functions
void Card::printCard()										//Printing cards details
{
		cout << endl << "Card name: " << getName() << endl;
		cout << "value: " << getVal() << endl;
		cout << "color: " << getColor() << endl;
}

void Card::printCardToFile(ofstream& outputFile)			//Printing cards details to output.txt
{
	outputFile << endl << "Card name: " << getName() << endl;
	outputFile << "value: " << getVal() << endl;
	outputFile << "color: " << getColor() << endl;
}
