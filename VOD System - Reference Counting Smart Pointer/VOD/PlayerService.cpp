#include "PlayerService.h"
#include <typeinfo>

SP<ViewAble> PlayerService::requestViewAble(string id_)
{
	++this->requests;
	for (unsigned int i = 0; i < this->database.size(); i++)
	{
		if (database[i]->getId().compare(id_) == 0)
		{
			return database[i];
		}
	}
	return NULL;
}

void PlayerService::addSeries(SP<ViewAble> seria)
{
	//SP<ViewAble> toView(seria);
	this->database.push_back(seria);
}

void PlayerService::addMovie(SP<ViewAble> movie)
{
	//SP<ViewAble> toView(movie);
	this->database.push_back(movie);	
}

void PlayerService::printMovie()
{
	cout << "MOVIES: " << endl;
	for (unsigned int i = 0; i < database.size(); i++)
	{
		if (strcmp(typeid(*database[i]).name(), "class Movie") == 0)
		{

			cout << endl << database[i]->getInfo() << endl;
		}
	}
}

void PlayerService::printSeries()
{
	cout << "SERIES: " << endl;
	for (unsigned int i = 0; i < database.size(); i++)
	{
		if (strcmp(typeid(*database[i]).name(), "class Series") == 0)
		{
			cout << endl << database[i]->getInfo() << endl;
		}
	}
}

void PlayerService::printItem(string &instruction)
{
	int i = 0;
	while (this->database[i]->getId().compare(instruction) != 0)
		++i;
	if (strcmp(typeid(*database[i]).name(), "class Series") == 0)
		cout << "printing Seria: " << endl;
	else
		cout << "Printing Movie: " << endl;
		cout << this->requestViewAble(instruction)->getInfo();
		cout << endl << "Number of watchers: " << this->requestViewAble(instruction)->getViewers().size() << endl;
	
}
