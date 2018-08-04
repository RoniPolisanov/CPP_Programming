//////////////////////////////////////////Roni Polisanov 307835884 Amit Shwartz 305432775//////////////////////////////////////////
#include <iostream>
#include <string>
#include <windows.h>
#include "Vector.h"
#include "MathVector.h"
#include "Polynomial.h"

using namespace std;

int main()
{ 
	int index = 0, index2 = 0, index3 = 0, FLAG = 1, pointer = 0;
	double fixed = 0;
	MathVector<double> Vec;								//dblMathVector
	MathVector<Polynomial> Vecpol;						//polMathVector
	Polynomial PolResult, Poly[5];						//pol_1 ...... pol_i
	string POLYNOMI;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//Related to menu

	for (int i = 0; i < 5; i++)							//Zeroing
	{
		Poly[i].getPolinom(0) = 0;
		Poly[i].getPolinom(1) = 0;
		Poly[i].getPolinom(2) = 0;
		Poly[i].getPolinom(3) = 0;
	}

	while (FLAG)										//MAIN MENU
	{
		SetConsoleTextAttribute(hConsole, 160);
		cout << " >>>>>>>>>>>>>>>>>>> MAIN MENU <<<<<<<<<<<<<<<<<<<< " << endl;
		string Menu[17] = { "POLYNOM Init \t\t\t\t - PRESS 1 ", "POLYNOM Operator+ \t\t\t - PRESS 2 ", "POLYNOM Operator- \t\t\t - PRESS 3 ", "POLYNOM Operator* \t\t\t - PRESS 4 ", "POLYNOM Operator/ \t\t\t - PRESS 5 ", "POLYNOM Operator= \t\t\t - PRESS 6 ", "POLYNOM PRINT \t\t\t\t - PRESS 7 ", "VECTOR Insert to dblMathVector \t - PRESS 8 ", "VECTOR Insert to polMathVector \t - PRESS 9 ", "VECTOR Resize \t\t\t\t - PRESS 10", "VECTOR Mean \t\t\t\t - PRESS 11", "VECTOR Sort \t\t\t\t - PRESS 12", "POLYNOM SET:Operator[] in polMathVector - PRESS 13", "GET: Operator[] in polMathVector\t - PRESS 14", "SET: Operator[] in dblMathVector\t - PRESS 15", "VECTOR PRINT\t\t\t\t - PRESS 55", "EXIT\t\t\t\t\t - PRESS 99" };
		SetConsoleTextAttribute(hConsole, 160);
		cout << " ";
		for (int i = 1; i < 17; ++i)
		{
			SetConsoleTextAttribute(hConsole, 160);		
			cout << "";
			if (i == 16)
			{
				SetConsoleTextAttribute(hConsole, 160);
				cout << "";
				SetConsoleTextAttribute(hConsole, 2);
				cout << Menu[15];
				SetConsoleTextAttribute(hConsole, 160);
				cout << " " << endl;

				SetConsoleTextAttribute(hConsole, 160);
				cout << " ";
				SetConsoleTextAttribute(hConsole, 9);
				cout << Menu[16];
				SetConsoleTextAttribute(hConsole, 160);
				cout << " " << endl;

				SetConsoleTextAttribute(hConsole, 160);
				cout << " ";
				break;
			}
			SetConsoleTextAttribute(hConsole, i);
			cout << Menu[i - 1];
			SetConsoleTextAttribute(hConsole, 160);
			cout << " " << endl;
			SetConsoleTextAttribute(hConsole, 160);
			cout << " ";
		}

		SetConsoleTextAttribute(hConsole, 160);
		cout << ">>>>>>>>>>>> WHAT WOULD YOU LIKE TO DO? <<<<<<<<<< " << endl;
		SetConsoleTextAttribute(hConsole, 8);
		cout << "* Your Choice: ";
		SetConsoleTextAttribute(hConsole, 15);
		cin >> pointer;

		switch (pointer)
		{
			case 1: // Operator*
			{
				cout << endl << "POLYNOMIAL INDEX TO INIT: ";
				cin >> index;
				cout << "YOUR POLYNOMIAL: ";;
				cin >> POLYNOMI;
				cout << "INITIALIZING 0%......................100% COMPLETED!" << endl;
				Poly[index].init(POLYNOMI);
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}

			case 2: // Operator+ 
			{
				cout << endl << "1ST POLYNOMIAL INDEX: ";
				cin >> index;
				cout << "2ND POLYNOMIAL INDEX: ";
				cin >> index2;
				cout << "TARGET POLYNOMIAL INDEX: ";
				cin >> index3;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Poly[index3] = Poly[index] + Poly[index2];
				cout << Poly[index3];
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}

			case 3: // Operator- 
			{
				cout << endl << "1ST POLYNOMIAL INDEX: ";
				cin >> index;
				cout << "2ND POLYNOMIAL INDEX: ";
				cin >> index2;
				cout << "TARGET POLYNOMIAL INDEX: ";
				cin >> index3;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Poly[index3] = Poly[index] - Poly[index2];
				cout << Poly[index3];
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}

			case 4: // Operator* 
			{
				cout << endl << "1ST POLYNOMIAL INDEX: ";
				cin >> index;
				cout << "SEVERAL SCALAR: ";
				cin >> fixed;
				cout << "TARGET POLYNOMIAL INDEX: ";
				cin >> index2;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Poly[index2] = Poly[index] * fixed;
				cout << Poly[index2];
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 5: // Operator/ 
			{
				cout << endl << "1ST POLYNOMIAL INDEX: ";
				cin >> index;
				cout << "SEVERAL SCALAR: ";
				cin >> fixed;
				cout << "TARGET POLYNOMIAL INDEX: ";
				cin >> index2;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Poly[index2] = Poly[index] / fixed;
				cout << Poly[index2];
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 6: // Operator =
			{
				cout << endl << "L-VALUE POLYNOMIAL INDEX: ";
				cin >> index;
				cout << "R-VALUE POLYNOMIAL INDEX: ";
				cin >> index2;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Poly[index] = Poly[index2];
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 7: // PRINT POLYNOM 
			{
				cout << endl << "INDEX OF POLYNOMIAL YOU WANT TO PRINT: ";
				cin >> index;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				cout << Poly[index];
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 8: // Insert to dblMathVector 
			{
				cout << endl << "OBJECT YOU WANT INSERT TO dblMathVector: ";
				cin >> fixed;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Vec.insert(fixed);
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 9: // Insert to polMathVector
			{
				cout << endl << "INDEX OF OBJECT YOU WANT INSERT TO polMathVector: ";
				cin >> index;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Vecpol.insert(Poly[index]);
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 10: // Resize 
			{
				cout << endl << "TO RESIZE dblMathVector PRESS '1'\nTO RESIZE polMathVector PRESS '2'\nYOUR CHOICE: ";
				cin >> index;
				cout << "NEW SIZE: ";
				cin >> index2;
				if (index == 1)
				{
					cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
					Vec.resize(index2);
				}
				else if (index == 2)
				{
					cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
					Vecpol.resize(index2);
				}
				else
					cerr << "FATAL ERROR >> WRONG INDEX";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
	
			}
			case 11: // Mean 
			{
				cout << endl << "TO MEAN dblMathVector PRESS '1'\nTO MEAN polMathVector PRESS '2'\nYOUR CHOICE: ";
				cin >> index;
				if (index == 1)
				{
					cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
					cout << Vec.mean();
				}
				else if (index == 2)
				{
					cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
					//PolResult = Vecpol.mean();
					
					cout << Vecpol.mean();
				}
				else
					cerr << "FATAL ERROR >> WRONG INDEX";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 12: // Sort 
			{
				cout << endl << "TO SORT dblMathVector PRESS '1'\nTO SORT polMathVector PRESS '2'\nYOUR CHOICE: ";
				cin >> index;
				cout << "FOR ASCENDING ORDER PRESS '1'\nFOR DESCENDING ORDER PRESS '2'\nYOUR CHOICE: ";
				cin >> index2;
				if (index == 1)
				{
					cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
					Vec.sort(index2);
				}
				else if (index == 2)
				{
					cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
					Vecpol.sort(index2);
				}
				else
					cerr << endl << "FATAL ERROR >> WRONG INDEX";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 13: // SET: Operator[] in polMathVector 
			{
				cout << endl << "L-VALUE INDEX: ";
				cin >> index2;
				cout << "R-VALUE INDEX: ";
				cin >> index;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Vecpol[index2] = Poly[index];
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 14: // GET: Operator[] in polMathVector 
			{
				cout << endl << "L-VALUE INDEX: ";
				cin >> index;
				cout << "R-VALUE INDEX: ";
				cin >> index2;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Poly[index] = Vecpol[index2];
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 15: // SET: Operator[] in dblMathVector 
			{
				cout << endl << "NUMBER VALUE: ";
				cin >> fixed;
				cout << "TARGET VECTOR: ";
				cin >> index2;
				cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
				Vec[index2] = fixed;
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 55: // PRINT VECTOR 
			{
				cout << endl << "TO PRINT dblMathVector PRESS '1'\nTO PRINT polMathVector PRESS '2'\nYOUR CHOICE: ";
				cin >> index2;
				if (index2 == 1)
				{
					cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
					cout << endl << Vec;
				}
				else if (index2 == 2)
				{
					cout << "EXECUTING 0%......................100% COMPLETED!" << endl;
					cout << endl << Vecpol;
				}
				else
					cerr << endl << "FATAL ERROR >> WRONG CHOICE";
				SetConsoleTextAttribute(hConsole, 8);
				cout << "* Press Enter to return to the main menu." << endl;
				SetConsoleTextAttribute(hConsole, 15);
				system("pause");
				break;
			}
	
			case 99: // EXIT ;
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "And that's it.\nGoodbye.\n";
				SetConsoleTextAttribute(hConsole, 15);
				FLAG = 0;
				break;
			}
		}
	}
	return 1;
}