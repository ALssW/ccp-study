#include <iostream>
using namespace std;

// 宏常量
#define Day 7


int main_103()
{
	// Day = 14  错误，常量不可修改
	cout << "一周有 " << Day << " 天。" << endl;

	const int month = 12;

	cout << "一年有 " << month << " 个月。" << endl;
	
	return 0;
}