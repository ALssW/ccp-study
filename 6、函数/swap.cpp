#include "swap.h"

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "½»»»ºó£ºa = " << a << ", b = " << b << endl;
}

int main_601()
{
	swap(10, 20);

	return 0;
}
