#ifndef __SERIES_H__
#define __SERIES_H__

#include <iostream>
#include "ViewAble.h"

using namespace std;

class Series : public ViewAble
{
public:
	//Constructor
	Series(string& _name, string& _id, unsigned int& _playRunTime, int season_, int episode_) : ViewAble(_name, _id, _playRunTime), season(season_), episode(episode_){}
	//Destructor
	~Series(){
		cout << " Series " << endl;
	}
	//C'Constructor
	Series(SP<Series> other) : ViewAble(other.GetPtr()->name, other.GetPtr()->id, other.GetPtr()->playRunTime){
		this->season = other.GetPtr()->season;
		this->episode = other.GetPtr()->episode;
	}
	//getting info about seria
	virtual string getInfo();
	//playing seria
	virtual bool play(){ cout << "play Seria" << endl; return true;  }

protected:
	int season,				
		episode;			
};

#endif