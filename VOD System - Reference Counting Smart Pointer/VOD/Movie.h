#ifndef __MOVIE_H__
#define __MOVIE_H__

#include <iostream>
#include "ViewAble.h"
#include "SP.h"
using namespace std;

class Movie : public ViewAble
{
public:
	//Movie Constructor
	Movie(string _name, string _id, unsigned int _playRunTime, bool oscarWinner_) : ViewAble(_name, _id, _playRunTime), oscarWinner(oscarWinner_) {}
	//Movie Destructor
	~Movie(){
		cout << " MOVIE" << endl;
	}
	//Movie Constructor
	Movie(SP<Movie> other) : ViewAble(other.GetPtr()->name, other.GetPtr()->id, other.GetPtr()->playRunTime){
		this->oscarWinner = other.GetPtr()->oscarWinner;
	}
	//Getting Movie info
	virtual string getInfo();
	//Play movie
	virtual bool play(){ cout << "play Movie" << endl; return true; }

protected:
	bool oscarWinner;
};

#endif