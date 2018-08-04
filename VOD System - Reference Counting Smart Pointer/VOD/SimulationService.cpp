#include "SimulationService.h"


SimulationService::SimulationService()
{
	playerServer = new PlayerService();
	clientServer = new ClientService();
	if (this->loadData())							//Checking if loading data succeeded
		this->executeSimulation();					//if yes - execute simulation.
	else
		cerr << "FATAL ERROR ::::: Loading VOD data UNSUCCEEDED" << endl;
}


SimulationService::~SimulationService()
{
	delete playerServer;
	delete clientServer;
}

bool SimulationService::loadData()					//Reading\Writing to files.
{
	ifstream clientFile("clientFile.txt"),
			 moviesFile("moviesFile.txt"),
			 seriesFile("seriesFile.txt");
	ofstream output("output.txt");
													
	if (!output.is_open()) { cerr << "Error opening input file" << endl; return false; }
	else if (!clientFile.is_open()) { cerr << "Error opening input file" << endl; return false; }
	else if (!moviesFile.is_open()) { cerr << "Error opening input file" << endl; return false; }
	else if (!seriesFile.is_open()) { cerr << "Error opening input file" << endl; return false; }
	
	size_t pos;
	string buffer , token_id, token_name, token_loc;
	getline(clientFile, buffer);
	while (!clientFile.eof())						//Copies the data from the file into a database.
	{
		getline(clientFile, buffer);
		if (buffer[0] != '#')			// && buffer[1] != '#' && buffer[2] != '#' && buffer[3] != '#'
		{
			pos = buffer.find(",");
			token_id = buffer.substr(0, pos);
			
			buffer.erase(0, pos + 1);
			pos = buffer.find(",");
			token_name = buffer.substr(0, pos);
			
			buffer.erase(0, pos + 1);
			token_loc = buffer.substr(0);
		
			this->clientServer->addClient(SP<Client>(new Client(token_id, token_name, token_loc)));
		}
		
	}
	clientFile.close();								//Closing clientFile.


	bool oscar;
	string token_run,token_oscar;
	unsigned int runtime;
	
	getline(moviesFile, buffer);
	while (!moviesFile.eof())						//Copies the data from the file into a database.
	{
		getline(moviesFile, buffer);
		if (buffer[0] != '#')
		{
			pos = buffer.find(",");
			token_id = buffer.substr(0, pos);
			buffer.erase(0, pos + 1);
			pos = buffer.find(",");
			token_name = buffer.substr(0, pos);
			buffer.erase(0, pos + 1);
			pos = buffer.find(",");
			token_run = buffer.substr(0, pos);
			buffer.erase(0, pos + 1);
			token_oscar = buffer.substr(0);

			if (token_oscar[0] == 'f')
				oscar = false;
			else
				oscar = true;

			runtime = atoi(token_run.c_str());

			this->playerServer->addMovie(SP<ViewAble>(new Movie(token_name, token_id, runtime, oscar)));
		}
	}
	moviesFile.close();								//Closing moviesFile.


	string token_epi, token_season;
	int episod, season;

	getline(seriesFile, buffer);
	while (!seriesFile.eof())						//Copies the data from the file into a database.
	{
		getline(seriesFile, buffer);
		if (buffer[0] != '#')
		{
			pos = buffer.find(",");
			token_id = buffer.substr(0, pos);
			buffer.erase(0, pos + 1);
			pos = buffer.find(",");
			token_name = buffer.substr(0, pos);
			buffer.erase(0, pos + 1);
			pos = buffer.find(",");
			token_epi = buffer.substr(0, pos);
			buffer.erase(0, pos + 1);
			pos = buffer.find(",");
			token_season = buffer.substr(0, pos);
			buffer.erase(0, pos + 1);
			token_run = buffer.substr(0);
			

			runtime = atoi(token_run.c_str());
			season = atoi(token_season.c_str());
			episod = atoi(token_epi.c_str());

			this->playerServer->addSeries(SP<Series>(new Series(token_name, token_id, runtime, season, episod)));
		}
	}
	seriesFile.close();								//Closing seriesFile.

	return true;									//Reading from files was succesfully.
}

bool SimulationService::executeSimulation()
{
	size_t pos;
	string id, buffer, instruction, token;
	ifstream  simulationFile("simulationFile.txt");
	if (!simulationFile.is_open()) { cerr << "Error opening input file" << endl; return false; }

	getline(simulationFile, buffer);
	while (!simulationFile.eof())
	{
		getline(simulationFile, buffer);
		if (buffer[0] != '#')
		{
			if (buffer.compare("printSeries") == 0)
				this->playerServer.GetPtr()->printSeries();

			else if (buffer.compare("printMovies") == 0)
				this->playerServer.GetPtr()->printMovie();

			else if (buffer.compare("printInactives") == 0)
				this->clientServer.GetPtr()->printInactive();

			else if (buffer.compare("update") == 0)
				this->update();

			else if (buffer[9] == ':')					//PRINT ITEM
			{
				pos = buffer.find(":");
				instruction = buffer.substr(pos + 1, buffer.size());
				this->playerServer->printItem(instruction);
			}

			else if (buffer[10] == ':')
			{
				pos = buffer.find(":");
				token = buffer.substr(0, pos );
				buffer.erase(0, pos + 1);
				instruction = buffer.substr(0);

				if (instruction.compare("stop") == 0)					//STOP WATCHING
				{
					for (unsigned int i = 0; i < this->clientServer.GetPtr()->getClient().size(); i++)
					{
						if (this->clientServer.GetPtr()->getClient()[i]->getID().compare(token) == 0)
						{
							this->clientServer.GetPtr()->getClient()[i]->getCurrentViewAble().GetPtr()->unRegister(clientServer.GetPtr()->getClient()[i]->getID());
							cout << this->clientServer.GetPtr()->getClient()[i]->getID() << " stoping viewable" << endl;
							break;
						}
					}
				}

				else					//PLAYER WANT WATCH "X" MOVIE
				{
					for (unsigned int i = 0; i < this->clientServer.GetPtr()->getClient().size(); i++)
					{
						if (this->clientServer->getClient()[i]->getID().compare(token) == 0)	 //find the player to update vieweble
						{
							if (this->clientServer->getClient()[i]->getCurrentViewAble() != 0)
							{	
								this->clientServer.GetPtr()->getClient()[i]->getCurrentViewAble().GetPtr()->unRegister(clientServer.GetPtr()->getClient()[i]->getID());	
								break;
							}
							this->clientServer->getClient()[i]->setCurrentViewAble(this->playerServer->requestViewAble(instruction)); //
							this->clientServer->getClient()[i]->getCurrentViewAble().GetPtr()->Register(clientServer.GetPtr()->getClient()[i]);	
							cout << "Client " << clientServer->getClient()[i]->getID() << " watching: " << endl << clientServer->getClient()[i]->getCurrentViewAble().GetPtr()->getInfo() << endl;
							break;
						}
					}
				}
			}
		}
	}
	return true;
}

void SimulationService::update()
{
	cout << "UPDATING\n";
	for (unsigned int i = 0; i < this->clientServer->getClient().size(); i++)
		this->clientServer->getClient()[i]->playViewAble();
}


	
	
