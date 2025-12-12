#include <iostream>
using namespace std;

int main_302()
{
	int a = 10;
	cout << "a = " << a << endl;

	a = 100;
	cout << "a = 100 = " << a << endl;

	cout << " a += 2 = " << (a += 2) << endl;
	cout << " a -= 2 = " << (a -= 2) << endl;
	cout << " a *= 2 = " << (a *= 2) << endl;
	cout << " a /= 2 = " << (a /= 2) << endl;
	cout << " a %= 2 = " << (a %= 2) << endl;

	return 0;
}
