#include <iostream>
#include <string>
#include <fstream>
#ifndef CARD_H
#define CARD_H

using namespace std;
enum Color{ Red, Green, Blue, Purple, Orange };

class Card											//Cards containing the data card by which others are fighting.
{
private:
	char* name;
	int val;
	Color color;

public:
	//Constructors
	Card(char* name, int val, char* color);
	Card();										  
	~Card();
	//Setters
	void setName(char* name);
	inline void setVal(int val);
	inline void setColor(char* token);

	//Getters
	inline const char* getName() const;
	inline const int getVal() const;
	inline const Color getColor() const;

	//Other
	void printCard();
	void printCardToFile(ofstream& outputFile);
};


#endif
