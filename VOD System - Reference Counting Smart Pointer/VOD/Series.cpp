#include "Series.h"

string Series::getInfo()
{
	string toReturn;
	string s1 = to_string(season);
	string s2 = to_string(episode);
	string s3 = to_string(playRunTime);
	return toReturn = "ID: " + id + ", Name: " + name + ", SEASON: " + s1 + ", EPISODE: " + s2 + ", PLAYRUNTIME: " + s3;
}