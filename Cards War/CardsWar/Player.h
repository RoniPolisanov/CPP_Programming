#include <iostream>
#include <string>
#include <fstream>
#include "Cards.h"
#include "Point.h"
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

const int MAX_C = 5;

class Player					//ID of the player, which contains five cards in which he fought against the other. The player includes the location field.
{
private:
	Card card[MAX_C];
	Point Position;
	char* name;
	char* id;
	int wins;
	int losses;
	int vacant_moves;			//Not in use yet

public:
	//Costructors
	Player(char* name, char* id, int losses, int wins, int x, int y, int vacant_moves); 
	Player();											
	~Player();

	//Setters
	void setName(char* name);
	void setID(char* id);
	inline void setWins(int wins);
	inline void setLosses(int losses);
	inline void set_vMoves(int vacant_moves);

	//Getters
	inline const char* getName() const;
	inline const char* getID() const;
	inline int getWins() const;
	inline int getLosses() const;
	inline int get_vMoves() const;

	//Other
	Card& getCard(int i);
	Point& getPoint();
	void printPlayer();
	void setPoint(int x, int y);
	//winMatch();				//Not in use yet				
	//loseMatch();				//Not in use yet

};

//Reading from file functions
void printPlayerToFile(ofstream& outputFile, Player& p);
void moveToPoint(Point &position);
void attackUsingCard(int val, Player &p);
void readLineFromPlayer(char* buffer, int& i, Player* p);
void readLineFromCard(char* buffer, Player& p, int& j);
void Commands(char* buffer, Player* p, ofstream& outputFile);


#endif 