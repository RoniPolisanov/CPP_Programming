#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__
#include <iostream>
#include <string>
//#include "MathVector.h"

using namespace std;


class Polynomial
{
private:
	double POLYNOM[4];								//The Polynomi X^3 X^2 X^1 X^0

public:
	Polynomial();
	~Polynomial();
	inline double& getPolinom(int i){ return POLYNOM[i]; };
	void init(string& poly);
	Polynomial& operator=(const Polynomial& Other);
	Polynomial operator+(const Polynomial& Other);
	Polynomial operator-(const Polynomial& Other);
	Polynomial operator/(const double &Other);

	Polynomial operator*(const double &Other);		//if we want Polynomi * num OR num * Polynomi
	friend Polynomial& operator*(const double Consty, const Polynomial& Other);

	bool operator==(const Polynomial& Other);
	bool operator!=(const Polynomial& Other);
	bool operator<(const Polynomial& Other);
	bool operator>(const Polynomial& Other);
	bool operator<=(const Polynomial& Other);
	bool operator>=(const Polynomial& Other);
	friend ostream& operator<<(ostream& COUT, Polynomial& Other);

};
///////////////////DESSTRUCTOR///////////////////
Polynomial::~Polynomial()
{
}

///////////////////CONSTRUCTOR///////////////////
Polynomial::Polynomial()
{
	for (int i = 0; i < 4; i++)
		getPolinom(i) = 0;
}

//EXAMPLE: -7.53*x^3+0.00*x^2+-1.00*x^1+7.00*x^0
////////////////INIT_POLYNOMI//////////////////
void Polynomial::init(string& poly)
{
	int to;
	double a;
	string s;
	while (true)
	{
		to = poly.find("*");
		if (to == -1)
		{
			cerr << "FATAL ERROR >> Inserted an invalid character! Polynomial only!\n";
			break;
		}
		s.substr(0, to);
		a = atof(poly.c_str());
		poly.erase(0, to);
		to = poly.find("+");
		switch (poly[3])
		{
		case '0':
			POLYNOM[3] += a;
			break;
		case '1':
			POLYNOM[2] += a;
			break;
		case '2':
			POLYNOM[1] += a;
			break;
		case '3':
			POLYNOM[0] += a;
			break;
		default:
			cerr << "FATAL ERROR >> Invailed Degree\n" << endl;
			break;
		}
		if (to == -1)
			break;
		poly.erase(0, to + 1);

	}

}

//////////////////OPERATOR =//////////////////
Polynomial& Polynomial::operator=(const Polynomial& Other)
{
	if (this == &Other)
		return *this;

	for (int i = 0; i < 4; i++)
		POLYNOM[i] = Other.POLYNOM[i];

	return *this;
}

//////////////////OPERATOR <<//////////////////
ostream& operator<<(ostream& COUT, Polynomial& Other)
{
	COUT << "OUTPUT >> FINAL POLYNOMI: ";
	COUT << Other.getPolinom(0) << "X^3+" << Other.getPolinom(1) << "X^2+" << Other.getPolinom(2) << "X^1+" << Other.getPolinom(3) << "X^0" << endl;
	COUT << endl;
	return COUT;
}


//////////////////OPERATOR +///////////////////
Polynomial Polynomial::operator+(const Polynomial& Other)
{
	Polynomial temp;
	temp.getPolinom(0) = POLYNOM[0] + Other.POLYNOM[0];
	temp.getPolinom(1) = POLYNOM[1] + Other.POLYNOM[1];
	temp.getPolinom(2) = POLYNOM[2] + Other.POLYNOM[2];
	temp.getPolinom(3) = POLYNOM[3] + Other.POLYNOM[3];
	return temp;
}

//////////////////OPERATOR -///////////////////
Polynomial Polynomial::operator-(const Polynomial& Other)
{
	Polynomial temp;
	temp.getPolinom(0) = POLYNOM[0] - Other.POLYNOM[0];
	temp.getPolinom(1) = POLYNOM[1] - Other.POLYNOM[1];
	temp.getPolinom(2) = POLYNOM[2] - Other.POLYNOM[2];
	temp.getPolinom(3) = POLYNOM[3] - Other.POLYNOM[3];
	return temp;
}

//////////////////OPERATOR *///////////////////
Polynomial Polynomial::operator*(const double &Other)
{
	Polynomial temp;
	if (Other == 0)
	{
		for (int i = 0; i < 4; i++)
			temp.getPolinom(i) = 0;
		return temp;
	}
	else
	{
		for (int i = 0; i < 4; i++)
			temp.getPolinom(i) = POLYNOM[i] * Other;;
		return temp;
	}
}

///////////////////OPERATOR *//////////////////
Polynomial& operator*(const double Consty, const Polynomial& Other)
{
	Polynomial temp;
	if (Consty == 0)
	{
		for (int i = 0; i < 4; i++)
			temp.getPolinom(i) = 0;
		return temp;
	}
	else
	{
		for (int i = 0; i < 4; i++)
			temp.getPolinom(i) = Consty * Other.POLYNOM[i];
		return temp;
	}
}

//////////////////OPERATOR "/"//////////////////
Polynomial Polynomial::operator/(const double &Other)
{
	Polynomial temp;
	if (Other == 0)
	{
		cerr << "FATAL ERROR >> POLYNOMIAL_DIVIDE_BY_ZERO" << endl;
		return temp;
	}
	else
	{
		for (int i = 0; i < 4; i++)
			temp.getPolinom(i) = POLYNOM[i] / Other;
		return temp;
	}
}

//////////////////OPERATOR ==///////////////////
bool Polynomial::operator==(const Polynomial& Other)
{
	if ((POLYNOM[0] == Other.POLYNOM[0]) && (POLYNOM[1] == Other.POLYNOM[1]) && (POLYNOM[2] == Other.POLYNOM[2]) && (POLYNOM[3] == Other.POLYNOM[3]))
		return true;
	return false;
}

//////////////////OPERATOR !=//////////////////
bool Polynomial::operator!=(const Polynomial& Other)
{
	return !(*this == Other);
}

///////////////////OPERATOR <//////////////////
bool Polynomial::operator<(const Polynomial& Other)
{
	int i = 0;
	while (i < 4)
	{
		if (POLYNOM[i] < Other.POLYNOM[i])
			return true;
		if (POLYNOM[i] > Other.POLYNOM[i])
			return false;
		if (POLYNOM[i] == Other.POLYNOM[i])
			i++;
	}
	return false;
}

///////////////////OPERATOR >//////////////////
bool Polynomial::operator>(const Polynomial& Other)
{
	int i = 0;
	while (i < 4)
	{
		if (POLYNOM[i] < Other.POLYNOM[i])
			return false;
		if (POLYNOM[i] > Other.POLYNOM[i])
			return true;
		if (POLYNOM[i] == Other.POLYNOM[i])
			i++;
	}
	return false;
}

//////////////////OPERATOR <=//////////////////
bool Polynomial::operator<=(const Polynomial& Other)
{
	int i = 0;
	while (i < 4)
	{
		if (POLYNOM[i] <= Other.POLYNOM[i])
			return true;
		if (POLYNOM[i] > Other.POLYNOM[i])
			return false;
		if (POLYNOM[i] == Other.POLYNOM[i])
			i++;
	}
	return true;
}

//////////////////OPERATOR >=//////////////////
bool Polynomial::operator>=(const Polynomial& Other)
{
	int i = 0;
	while (i < 4)
	{
		if (POLYNOM[i] < Other.POLYNOM[i])
			return false;
		if (POLYNOM[i] >= Other.POLYNOM[i])
			return true;
		if (POLYNOM[i] == Other.POLYNOM[i])
			i++;
	}
	return true;
}



#endif