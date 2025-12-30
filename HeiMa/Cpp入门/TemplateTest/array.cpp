#include <iostream>
#include "array.h"

int main_1002()
{
	Array<int> arr(10);

	for (int i = 0; i < 10; ++i)
	{
		arr.add(i);
	}

	for (int i = 0; i < arr.getSize(); ++i)
	{
		std::cout << arr[i] << " ";
	}

	arr.removeLast();

	for (int i = 0; i < arr.getSize(); ++i)
	{
		std::cout << arr[i] << " ";
	}

	return 0;
}
