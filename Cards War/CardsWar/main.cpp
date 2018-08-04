//////////////////////////////////////////Roni Polisanov 307835884 Amit Shwartz 305432775//////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "Player.h"

using namespace std;

int main(int argc, char** argv)
{
	char buffer[200] = { 0 };							
	int i = 0, j = 0, k = 0;
	ofstream outputFile("output.txt");					//Openning output.txt to writing
	if (!outputFile.is_open()) { cerr << "Error opening input file" << endl; return -1; }
	ifstream inputFile("creation.txt");					//Reading from the file creation.txt
	if (!inputFile.is_open()) { cerr << "Error opening input file" << endl; return -1; }
	else
	{
		while (!inputFile.eof()) 						//Count number of players in file to allocate dynamic memory
		{
			inputFile.getline(buffer, 200);
			if (buffer[0] == 'P')
				++j;
		}
		Player *p = new Player[j];						//Allocating players memory
		if (p == NULL) { cerr << "Error allocation memory" << endl; return -1; }
		inputFile.close();

		ifstream inputFile("creation.txt"); 			//Reading file for cutting lines
		if (!inputFile.is_open()) { cerr << "Error opening input file" << endl; return -1; }
		while (!inputFile.eof())
		{
			inputFile.getline(buffer, 200);				//Cutting line from file
			switch (buffer[0])
			{
			case 'P':
				readLineFromPlayer(buffer, i, p);		//Set players details
				j = 0;
				break;
			case 'C':
				readLineFromCard(buffer, p[i - 1], j);	//Set players cards details						
				break;
			case '#':									
				break;
			default:
				break;
			}
		}
		ifstream inputFile2("simulation.txt");			//reading from the file simulation.txt
		if (!inputFile.is_open()) { cerr << "Error opening input file" << endl; return -1; }
		else
		{
			while (!inputFile2.eof())
			{
				inputFile2.getline(buffer, 200);		//Cutting line from file
				if ((buffer[0] != '#') && (buffer[0] != '\0') && (buffer[0] != 'e')) 
					Commands(buffer, &p[0], outputFile);//Sending buffer 
			}
			cout << endl << "Reading from file is complete, have a nice day!" << endl << endl;
		}
		inputFile.close();								//Close creation.txt
		inputFile2.close();								//Close simulation.txt
		outputFile.close();								//Close output.txt
		if (p != NULL) delete[] p;						//Safe free
	}
	system("pause");
	return 1;
}