#ifndef __PLAYERSERVICE_H__
#define __PLAYERSERVICE_H__

#include <iostream>
#include "ViewAble.h"
#include "Series.h"
#include "Movie.h"

using namespace std; 

class PlayerService
{
private:
	vector<SP<ViewAble>> database;
	unsigned int requests;

public:
	//Getting database
	vector<SP<ViewAble>>& getDatabase(){ return database; }	
	//Requiesting to vieable
	SP<ViewAble> requestViewAble(string id_);	
	//adding seria
	void addSeries(SP<ViewAble> seria);
	//adding move
	void addMovie(SP<ViewAble> movie);	
	//TOTAL REQUESTS from service to movie\seria
	inline const unsigned int totalRequestsFromService() const { return this->requests; }	
	//printing movies
	void printMovie();
	//printing serias
	void printSeries();
	//printing items
	void printItem(string& instruction);
	//Constructor
	PlayerService() : requests(0) {}
	//Destructor
	~PlayerService(){
		database.clear();
		cout << " player SERVICE" << endl;
	}
};

#endif