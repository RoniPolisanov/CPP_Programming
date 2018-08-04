#ifndef __SIMULATIONSERVICE_H__
#define __SIMULATIONSERVICE_H__

#include <iostream>
#include <fstream>
#include <ostream>
#include "ClientService.h"
#include "PlayerService.h"
#include "SP.h"

using namespace std;

class SimulationService
{
private:
	SP<ClientService> clientServer;
	SP<PlayerService> playerServer;

public:
	//updating the movie\seria
	void update();
	//loading data from the file
	bool loadData();
	//executing the simulation file 
	bool executeSimulation();
	//constructor
	SimulationService();
	//destructor
	~SimulationService();
};

#endif