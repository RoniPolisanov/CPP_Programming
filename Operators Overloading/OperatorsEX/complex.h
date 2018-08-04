#ifndef COMPLEX_H
#define COMPLEX_H


#include <iostream>
using namespace std;

class Complex
{
public:
	inline Complex(double dRealInit = 0, double dImaginaryInit = 0);

	inline const Complex operator-() const;
	inline const Complex& operator++();    // pre increment
	inline const Complex& operator--();
	const Complex  operator++(int);        // post increment
	const Complex  operator--(int);
	const Complex& operator+=(const Complex& rc);
	const Complex& operator-=(const Complex& rc);

	friend istream& operator>>(istream& ris, Complex& rc);

	inline double getReal() const;
	inline double getImaginary() const;

private:
	double dReal,
		dImaginary;
};

const Complex operator+(const Complex& rc1, const Complex& rc2);
const Complex operator-(const Complex& rc1, const Complex& rc2);
bool operator==(const Complex& rc1, const Complex& rc2);
inline bool operator!=(const Complex& rc1, const Complex& rc2);
ostream& operator<<(ostream& ros, const Complex& rc);




Complex::Complex(double dRealInit, double dImaginaryInit)
	: dReal(dRealInit), dImaginary(dImaginaryInit)
{}


const Complex Complex::operator-() const
{
	return Complex(-dReal, -dImaginary);
}


const Complex& Complex::operator++()
{
	++dReal;
	++dImaginary;
	return *this;
}


const Complex& Complex::operator--()
{
	--dReal;
	--dImaginary;
	return *this;
}


double Complex::getReal() const
{
	return dReal;
}


double Complex::getImaginary() const
{
	return dImaginary;
}


inline bool operator!=(const Complex& rc1, const Complex& rc2)
{
	return !(rc1 == rc2);
}


#endif