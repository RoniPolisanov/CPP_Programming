#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <iostream>
#include <string>
#include "SP.h"

class ViewAble;

using namespace std;

class Client
{
private:
	string id, name, Location;
	float timer;
	SP<ViewAble> currentViewAble;

public:
	//Client Constructor
	Client(string id_ = "NONE", string name_ = "NONE", string Location_ = "NONE") : timer(0), currentViewAble(NULL)
	{
		this->id = id_;
		this->name = name_;
		this->Location = Location_;
	}
	//Cient Destructor
	~Client(){
		cout << " CLIENT" << endl;
	}
	//Setting current viewable MOVIES\SERIES
	void setCurrentViewAble(SP<ViewAble> other){ this->currentViewAble = other; }
	//Getting current ViewAble
	const inline SP<ViewAble> getCurrentViewAble() const { return this->currentViewAble; }
	//Stopping current ViewAble
	void stopViewAble(){ this->currentViewAble = 0; }
	//Getting id
	inline const string getID() const { return id; }
	//Playing ViewAble
	bool playViewAble();

};

#endif
