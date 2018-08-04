#include "ViewAble.h"

bool ViewAble::Register(SP<Client>& other)
{
	for (unsigned int i = 0; i < currentlyWatchingMe.size(); i++)
	{
		if (this->currentlyWatchingMe.at(i)->getID().compare( other->getID()) == 0)
			return false;
	}
	other->setCurrentViewAble(this);
	this->currentlyWatchingMe.push_back(other);
	return true;
}



bool ViewAble::unRegister(string id)
{
	for (unsigned int i = 0; i < currentlyWatchingMe.size(); i++)
	{
		if (this->currentlyWatchingMe.at(i)->getID() == id)
		{
			this->currentlyWatchingMe.erase(currentlyWatchingMe.begin() + i);
			return true;
		}
	}
	return false;
}