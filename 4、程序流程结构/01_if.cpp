#include <iostream>
using namespace std;

int main_401()
{
	// 单行形式 if
	int input;
	cout << "请输入一个整数";
	cin >> input;

	if (input >= 10)
	{
		cout << "输入的整数大于等于10" << endl;
	}

	cout << "\n";

	// 多行形式 if...else
	cout << "请输入一个整数";
	cin >> input;

	if (input >= 10)
	{
		cout << "输入的整数大于等于10" << endl;
	}
	else
	{
		cout << "输入的整数小于10" << endl;
	}

	cout << "\n";

	// 多条件形式 if...else if... else
	cout << "请输入一个整数";
	cin >> input;

	if (input > 10)
	{
		cout << "输入的整数大于10" << endl;
	}
	else if (input == 10)
	{
		cout << "输入的整数等于10" << endl;
	}
	else
	{
		cout << "输入的整数小于10" << endl;
	}


	return 0;
}
