#include <iostream>
#include <string>
#include <fstream>
#include "Point.h"

//C'tors
Point::Point()											//Constructor
{
	cout << "Point Constructor Activated." << endl;
	setPosX(0);
	setPosY(0);
	cout << "Constructor quit." << endl;

};

Point::~Point()											//Destructor
{
	cout << "Point Destructor Activated." << endl;

	cout << "Destructor quit." << endl;
};

//Setters
void Point::setPosX(int x) { this->PosX = x; }			//Setting player position x in number line
void Point::setPosY(int y) { this->PosY = y; }			//Setting player position y in number line

//Getters
int Point::getPosX() { return this->PosX; }				//Getting player position x in number line
int Point::getPosY() { return this->PosY; }				//Getting player position y in number line

