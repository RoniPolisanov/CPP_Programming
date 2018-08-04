#ifndef __MATHVECTOR_H__
#define __MATHVECTOR_H__
#include "Vector.h"

template <class T>
class MathVector : public Vector<T>
{
public:
	MathVector(int num = 0);	 //Vector constructor (Creating Vector)
	~MathVector();
	T mean();
	void sort(int& sort);
};

///////////////////DESSTRUCTOR///////////////////
template <class T>
MathVector<T>::~MathVector()
{
}

///////////////////CONSTRUCTOR///////////////////
template <class T>
MathVector<T>::MathVector(int num = 0)
{
	Vector<T>::Vector();
	cout << "MATHVECTOR C'TOR\n";
}

//////////////////////SORT/////////////////////
template <class T>
void MathVector<T>::sort(int& sort)
{
	if (sort == 1)							//ASCENDING ORDER
	{
		T temp;
		for (int i = this->getSize() - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (this->arr[j] > this->arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		return;
	}
	else									//DESCENDING ORDER
	{
		T temp;
		for (int i = this->getSize() - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (this->arr[j] < this->arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		return;
	}
}

///////////////////MEAN ///////////////////
template <class T> T MathVector<T>::mean() {
	T temp;
	for (int i = 0; i < this->getSize(); i++){
		if (i == 0) temp = arr[i];
		else temp = temp + arr[i];
	}

	return this->getSize() ? temp / this->getSize() : temp;
}


#endif


