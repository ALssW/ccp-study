#include <iostream>
using namespace std;

int main()
{

	int a;
	cout << "请输入一个整数（1-5）：";
	cin >> a;
	switch (a)
	{
		case 1:
			cout << "你输入的是数字 1" << endl;
			break;
		case 2:
			cout << "你输入的是数字 2" << endl;
			break;
		case 3: 
			cout << "你输入的是数字 3" << endl;
			break;
		case 4:
			cout << "你输入的是数字 4" << endl;
			break;
		case 5:
			cout << "你输入的是数字 5" << endl;
			break;
		default:
			cout << "你输入的数字不在范围内" << endl;
			break;
	}


	return 0;
}