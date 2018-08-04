#include "complex.h"

int main()
{
	Complex c1(1, 1), c2(2, 2), c3(3, 3), c4;

	c4 = c1 + c2;
	cout << c4 << endl;

	c4 = c2 - c3;
	cout << c4 << endl;

	c4 += c3 + --c2;
	cout << c4 << endl;

	c4 -= 3;
	cout << c4 << endl;

	if (c4 != c3)
	{
		cout << "c4 differs from c3 \n";
	}

	return 0;
}



/**** output ****

3+3i
-1-1i
3+3i
0+3i
c4 differs from c3

*****************/














