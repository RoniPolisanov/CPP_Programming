#ifndef __CLIENTSERVICE_H__
#define __CLIENTSERVICE_H__

#include <iostream>
#include "Client.h"
#include "SP.h"
#include "ViewAble.h"

using namespace std;

class ClientService
{
private:
	vector<SP<Client>> clients;

public:
	//Getting ViewAble
	SP<ViewAble> getViewAble(string id);
	//To add client
	bool addClient(SP<Client>& other);
	//To get client
	inline vector<SP<Client>> getClient() { return this->clients; }
	//Printing all the inactive	
	void printInactive();
	//Client Constructor
	ClientService();
	//Client Destructor
	~ClientService();

};

#endif