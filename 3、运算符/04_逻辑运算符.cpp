#include <iostream>
using namespace std;

int main_304()
{
	
	int a = 10;
	int b = 20;

	cout << " a = " << a << endl;
	cout << " b = " << b << endl;

	cout << " a != 10" << (a != 10) << endl;
	cout << " !a = " << !a << endl;
	cout << " !!a = " << !!a << endl;
	cout << " !!!a = " << !!!a << endl;

	cout << " (a < b) && (a != b) = " << ((a < b) && (a != b)) << endl;
	cout << " (a > b) || (a != b) = " << ((a > b) || (a != b)) << endl;

	return 0;
}
