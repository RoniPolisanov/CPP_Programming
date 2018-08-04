#include "Movie.h"


string Movie::getInfo()
{
	string toReturn;
	string s1 = to_string(playRunTime);
	if (oscarWinner)
	{
		toReturn = "ID: " + id + ", Name: " + name + ", PLAYRUNTIME: " + s1 + ", OSCAR WINNER MOVIE";
		return toReturn;
	}
	toReturn = "ID: " + id + ", Name: " + name + ", PLAYRUNTIME: " + s1 + ", NOT OSCAR WINNER MOVIE";
	return toReturn;
}