#include "ClientService.h"


ClientService::ClientService()
{
}


ClientService::~ClientService()
{
	clients.clear();
	cout << " CLIENT SERVICE" << endl;

}

bool ClientService::addClient(SP<Client>& other)
{
	if (other.GetPtr() != NULL)
	{
		this->clients.push_back(other);
		return true;
	}
	return false;
}

SP<ViewAble> ClientService::getViewAble(string id)
{
	for (unsigned int i = 0; i < this->clients.size(); i++)
	{
		if (this->clients[i].GetPtr()->getID() == id)
			return this->clients[i].GetPtr()->getCurrentViewAble();
	}
	return NULL;
}
void ClientService::printInactive()
{
	int j = 0;
	cout << "Currently Not Watching (INACTIVE CLIENTS): " << endl;
	for (unsigned int i = 0; i < clients.size(); i++)
	{
		if (!clients[i].GetPtr()->getCurrentViewAble())
		{
			cout << "#" << j << " Client ID: " << clients[i].GetPtr()->getID() << endl;
			j++;
		}
	}
}