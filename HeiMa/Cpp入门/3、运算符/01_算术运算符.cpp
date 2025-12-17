#include <iostream>
using namespace std;

int main_301()
{
	int a = 10;
	int b = 20;
	cout << "a = " << a << ", b = " << b << endl;

	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;
	cout << '\n';

	// int / int = int
	cout << "a / b = " << a / b << endl;
	cout << "(a * 1.f) / (b * 1.f)= " << (a * 1.f) / (b * 1.f) << endl;
	cout << '\n';

	cout << "a % b = " << a % b << endl;
	cout << "b % a = " << b % a << endl;
	cout << '\n';

	cout << "a = " << a << ", b = " << b << endl;
	cout << "a++ = " << a++ << endl;
	cout << "++b = " << ++b << endl;
	cout << "a-- = " << a-- << endl;
	cout << "--b = " << --b << endl;
	cout << "a = " << a << ", b = " << b << endl;

	return 0;
}
