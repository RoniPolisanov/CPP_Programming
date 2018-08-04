#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>

using namespace std;


template <class T>
class Vector
{
protected:
	int size,
		capacity;
	T* arr;
	 
public:
	Vector(int _capacity = 0);
	Vector(const Vector<T>& Other);
	~Vector();

	inline int getSize() const {return this->size;};
	inline int getCapacity() const { return this->capacity; };

	inline void resize(int index);
	inline void insert(const T& value);

	inline T& operator[](int index);
	Vector<T>& operator=(const Vector<T>& Other);
	template<class T> friend ostream& operator<<(ostream& COUT, const Vector<T>& Other);

};

///////////////////DESSTRUCTOR///////////////////
template<class T>
Vector<T>::~Vector()
{
	delete[] arr;
}

///////////////////CONSTRUCTOR///////////////////
template<class T>
Vector<T>::Vector(int _capacity = 0)
{
	cout << "VEC CONTRUCTOR\n";
	capacity = _capacity;
	size = 0;
	arr = new T[capacity];
}

/////////////////COPY CONSTRUCTOR/////////////////
template<class T>
Vector<T>::Vector(const Vector<T>& Other)
{
	arr = new T[Other.capacity];
	if (arr == NULL) cerr << "Error Allocating Memmory" << endl;
	for (int i = 0; i < Other.size; i++)
		arr[i] = Other.arr[i];
}

///////////////ASSIGHMENT OPERATOR///////////////
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& Other)
{
	if (this == &Other)
		return *this;
	delete[] arr;

	size = Other.size;
	capacity = Other.capacity;
	arr = new T[capacity];
	if (arr == NULL) cerr << "Error Allocating Memmory" << endl;
	for (int i = 0; i < size; i++)
		arr[i] = Other.arr[i];
	return *this;
}

/////////////////INSERT TO VECTOR/////////////////
template<class T>
void Vector<T>::insert(const T& value)
{
	if (capacity == 0)
	{
		++capacity;
		arr = new T[capacity];
		if (arr == NULL) cerr << "Error Allocating Memmory" << endl;
	}

	else if (size == capacity)
	{
		capacity *= 2;
		Vector<T> temp(*this);

		delete[] arr;
		arr = new T[capacity];
		if (arr == NULL) cerr << "Error Allocating Memmory" << endl;
		for (int i = 0; i < size; i++)
			arr[i] = temp.arr[i];
	}
	arr[size] = value;
	++size;
}

//////////////////OPERATOR []//////////////////
template<class T>
T& Vector<T>::operator[](int index)
{
	return arr[index];
}

//////////////////OPERATOR <<//////////////////
template<class T>
ostream& operator<<(ostream& COUT, const Vector<T>& Other) //|size:5|capacity:8|5,7,12,44,5|
{
	COUT << "V E C T O R >> ";
	COUT << "| SIZE: " << Other.size << " | CAPACITY: " << Other.capacity << " | ";
	COUT << "ARRAY: ";
	for (int i = 0; i < Other.size; i++)
	{
		if (Other.size - i != 1)
			COUT << Other.arr[i] << ", ";
		else
			COUT << Other.arr[i];
	}
	COUT << " |" << endl;
	return COUT;
}

////////////////////RESIZE////////////////////
template<class T>
void Vector<T>::resize(int index)
{
	capacity = index;
	if (capacity == 0)
	{
		delete[] arr;
		size = 0;
		return;
	}
	if (size > capacity)
	{
		size = capacity;
	}
	Vector<T> temp(*this);
	delete[] arr;
	arr = new T[capacity];
	if (arr == NULL) cerr << "Error Allocating Memmory" << endl;
	for (int i = 0; i < size; i++)
		arr[i] = temp.arr[i];
}


#endif