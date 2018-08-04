#ifndef __VIEWABLE_H__
#define __VIEWABLE_H__

#include <iostream>
#include <vector>
#include "SP.h"
#include "Client.h"

using namespace std;

class ViewAble
{
protected:
	string name, id;
	unsigned int playRunTime;
	vector<SP<Client>> currentlyWatchingMe;

public:
	//Constructor
	ViewAble(string _name, string _id, unsigned int _playRunTime) : name(_name), id(_id), playRunTime(_playRunTime) {}
	//Descturctor
	virtual	~ViewAble() {}
	//getting info from movie or seria
	virtual string getInfo() = 0;
	//getting id
	const string getId() const { return this->id; }
	//getting the PLAYING RUN TIME!!!
	inline const unsigned int getTime() const { return this->playRunTime; }
	//registering 
	bool Register(SP<Client>& other);
	//unregistering
	bool unRegister(string id);
	//playing the movie or the seria
	virtual bool play() = 0;
	//getting all the currently who watching
	inline const vector<SP<Client>> getViewers() const { return this->currentlyWatchingMe; }
};

#endif