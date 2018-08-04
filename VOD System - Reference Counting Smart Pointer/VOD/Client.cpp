#include "Client.h"


bool Client::playViewAble()
{
	if ((this->currentViewAble.GetPtr()) != NULL)
	{
		this->timer += 5;
		cout << "viewr ID: " << this->getID() << " runtime: " << timer << endl;
		return true;
	}
	return false;
}
