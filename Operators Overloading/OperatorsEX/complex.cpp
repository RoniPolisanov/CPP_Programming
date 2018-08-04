#include "complex.h"

const Complex Complex::operator++(int)
{
	Complex cTemp(*this);
	++dReal;
	++dImaginary;
	return cTemp;
}


const Complex Complex::operator--(int)
{
	Complex cTemp(*this);
	--dReal;
	--dImaginary;
	return cTemp;
}


const Complex& Complex::operator+=(const Complex& rc)
{
	dReal += rc.getReal();
	dImaginary += rc.getImaginary();

	return *this;
}


const Complex& Complex::operator-=(const Complex& rc)
{
	dReal -= rc.getReal();
	dImaginary -= rc.getImaginary();

	return *this;
}


istream& operator>>(istream& ris, Complex& rc)
{
	return ris >> rc.dReal >> rc.dImaginary;
}


ostream& operator<<(ostream& ros, const Complex& rc)
{
	ros << rc.getReal();
	if (rc.getImaginary() > 0)
	{
		ros << '+';
	}
	ros << rc.getImaginary() << 'i';
	return ros;
}


const Complex operator+(const Complex& rc1, const Complex& rc2)
{
	return Complex(rc1) += rc2;
}


const Complex operator-(const Complex& rc1, const Complex& rc2)
{
	return Complex(rc1) -= rc2;
}


bool operator==(const Complex& rc1, const Complex& rc2)
{
	if (rc1.getReal() == rc2.getReal() &&
		rc1.getImaginary() == rc2.getImaginary())
	{
		return true;
	}
	else
	{
		return false;
	}
}
