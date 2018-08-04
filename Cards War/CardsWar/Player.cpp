#include <iostream>
#include <string>
#include <fstream>
#include "Player.h"

using namespace std;

const char* defaultName = "Pimp";
const char* defaultID = "69";

// C'tors
Player::Player(char* name, char* id, int losses, int wins, int x, int y, int vacant_moves)
{																//Constructor
	cout << "Player Constructor Activated." << endl;
	Position.setPosX(x);
	Position.setPosY(y);
	setName(name);
	setID(id);
	setLosses(losses);
	setWins(wins);
	set_vMoves(vacant_moves);
	cout << "Constructor quit." << endl;
}

Player::Player() : wins(0), losses(0), vacant_moves(0)			//Constructor
{
	cout << "Player Constructor Activated." << endl;
	Position.setPosX(0);
	Position.setPosY(0);
	setID(0);
	setName(0);
	cout << "Constructor quit." << endl;
}

Player::~Player()												//Destructor
{
	cout << "Player Destructor Activated." << endl;
	if (name != NULL) delete[] name;
	if (id != NULL) delete[] id;
	cout << "Destructor quit." << endl;
}

//Getters
const char* Player::getName() const { return this->name; }		//getting players name
const char* Player::getID() const { return this->id; }			//getting players id
int Player::getWins() const { return this->wins; }				//getting wins count
int Player::getLosses() const { return this->losses; }			//getting losses count
int Player::get_vMoves() const { return this->vacant_moves; }	//getting players free moves
Card& Player::getCard(int i) { return this->card[i]; }			//getting desired card
Point& Player::getPoint() { return Position; }					//getting the player point

//Setters
void Player::setWins(int wins){ this->wins = wins; }			//Count how many wins player have
void Player::setLosses(int losses){ this->losses = losses; }	//Count how many losses player have
void Player::set_vMoves(int vacant_moves){ this->vacant_moves = vacant_moves; }		//Sets player free moves //Not in use yet..

void Player::setName(char *name)								//Setting name of the player 
{
	if (name != NULL)
	{
		this->name = new char[strlen(name) + 1];
		if (this->name == NULL) { cerr << "Error allocation memory" << endl; return; }
		strcpy(this->name, name);
		return;
	}
	else
	{
		this->name = new char[strlen(defaultName) + 1];
		if (this->name == NULL) { cerr << "Error allocation memory" << endl; return; }
		strcpy(this->name, defaultName);
	}
}

void Player::setID(char *id)									//Setting id of the player
{
	if (id != NULL)
	{
		this->id = new char[strlen(id) + 1];
		if (this->id == NULL) { cerr << "Error allocation memory" << endl; return; }
		strcpy(this->id, id);
		return;
	}
	else
	{
		this->id = new char[strlen(defaultID) + 1];
		if (this->id == NULL) { cerr << "Error allocation memory" << endl; return; }
		strcpy(this->id, defaultID);
	}
}

//Other functions
void readLineFromPlayer(char* buffer, int& i, Player* p)		//Cutting the line and setting player details 
{
	char* token;
	char* token2;

	token = strtok(buffer,",");									//ID
	token = strtok(NULL,",");
	p[i].setID(token);
	
	token = strtok(NULL, ",");									//NAME
	p[i].setName(token);
	
	token = strtok(NULL, ",");									//WINS
	p[i].setWins(atoi(token));

	token = strtok(NULL,  ",");									//LOSSES
	p[i].setLosses(atoi(token));

	token = strtok(NULL, ":");									//POSX
	token2 = strtok(NULL, "\n");								//POSY
	p[i].setPoint((atoi(token)),atoi(token2));	

	++i;
}

void readLineFromCard(char* buffer, Player &p, int& j)			//Cutting the line and setting card details
{
	if (j > 5) { cerr << "Wrong index of card" << endl; return; }	//Check if card index in range
	char* token;
		
	token = strtok(buffer, ",");								//NAME
	token = strtok(NULL, "\"");
	token = strtok(NULL, "\"");
	p.getCard(j).setName(token);

	token = strtok(NULL, ",");									//VALUE
	p.getCard(j).setVal(atoi(token));

	token = strtok(NULL, "\n");									//COLOR
	p.getCard(j).setColor(token);
	++j;
}

void Player::printPlayer()										//Printing full player details + full deck details
{
	int j;
	cout << endl << "Player name: " << getName() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Wins: " << getWins() << endl;
	cout << "Losses: " << getLosses() << endl;
	cout << "POSX: " << getPoint().getPosX() << endl;
	cout << "POSY: " << getPoint().getPosY() << endl;
	cout << "Vacant Moves: " << get_vMoves() << endl;
	cout << "Player Card's:" << endl;
	for (j = 0; j < 5; j++)
	getCard(j).printCard();										
}

void Player::setPoint(int x, int y)								//Setting Point of the player						
{
	getPoint().setPosX(x);
	getPoint().setPosY(y);
}

void moveToPoint(Point& position)								//Not so obvious, it will be clear in next homework
{
	cout << " MOVE TO: " << position.getPosX() << ":" << position.getPosY() << endl;
}

void attackUsingCard(int index, Player &p)						//Not so obvious, it will be clear in next homework
{
	cout << "ATTACKING PLAYER ID: " << p.getID() << " " << "WITH CARD INDEX: " << index << endl;
}

void Commands(char* buffer, Player* p, ofstream& outputFile)	//Cutting line from simulation and execute the commands
{
	int k = 0, j = 0, index = 0;
	char id[8];
	char* x;
	char* token = strtok(buffer, " ");
	strcpy(id, token);											//PLAYER ID 
	token = strtok(NULL, " ");

	while (strcmp(p[k].getID(), id) != 0)						//ALLOCATING PLAYER
		k++;

	switch (token[0])
	{
	case 'M':													//MOVE
		x = strtok(NULL, ":");
		token = strtok(NULL, "/n");
		p[k].setPoint(atoi(x),atoi(token));
		outputFile << endl << "PLAYER ID: " << p[k].getID();
		cout << endl << "PLAYER ID: " << p[k].getID();
		outputFile << " MOVE TO: " << p[k].getPoint().getPosX() << ":" << p[k].getPoint().getPosY() << endl;
		moveToPoint(p[k].getPoint());
		break;
	case 'P':													//PRINT
		p[k].printPlayer();
		printPlayerToFile(outputFile, p[k]);
		break;
	case 'A':													//ATTACK
		token = strtok(NULL, " ");
		while (strcmp(p[j].getID(), token) != 0)				//ALLOCATING PLAYER TO ATTCAK
			j++;
		token = strtok(NULL, "/n");
		index = atoi(token);									//CARD ATTACK WITH INDEX

		outputFile << endl << "PLAYER ID: " << p[k].getID() << " ";
		outputFile << "ATTACKING PLAYER ID: " << p[j].getID() << " " << "WITH CARD INDEX: " << index << endl;
		cout << endl << "PLAYER ID: " << p[k].getID() << " ";
		attackUsingCard(index, p[j]);							//BATTLE
		break;
	}
}

void printPlayerToFile(ofstream& outputFile, Player& p)			//Printing full player details + full deck details
{
	int j;
	outputFile << endl << "Player name: " << p.getName() << endl;
	outputFile << "ID: " << p.getID() << endl;
	outputFile << "Wins: " << p.getWins() << endl;
	outputFile << "Losses: " << p.getLosses() << endl;
	outputFile << "POSX: " << p.getPoint().getPosX() << endl;
	outputFile << "POSY: " << p.getPoint().getPosY() << endl;
	outputFile << "Vacant Moves: " << p.get_vMoves() << endl;
	outputFile << "Player Card's:" << endl;
	for (j = 0; j < 5; j++)
		p.getCard(j).printCardToFile(outputFile);
}

