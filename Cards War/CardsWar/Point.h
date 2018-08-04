#include <iostream>
#include <string>
#include <fstream>
#ifndef POINT_H
#define POINT_H
using namespace std;


class Point								//The point describes the position of the player on the field.
{
private:
	int PosX;
	int PosY;

public:
	//C'tors
	Point();
	~Point();

	//Setters
	void setPosX(int x);
	void setPosY(int y);

	//Getters
	int getPosX();
	int getPosY();
};

#endif