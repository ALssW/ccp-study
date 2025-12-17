#include <iostream>
using namespace std;

int main_402()
{
	cout << "三目运算符示例：" << endl;
	cout << "10 > 2 ? '是' : '否' 的结果是： " << (10 > 2 ? "是" : "否") << endl;

	cout << "\n";

	// 在 C++ 中如果三目运算符返回的是变量，可以继续复制
	int a = 100;
	int b = 10;
	cout << "初始值 a = " << a << ", b = " << b << endl;
	(a > b ? a : b) = 20; // 将较大值赋给 c
	cout << "(a > b ? a : b) = 20, a = " << a << endl;

	return 0;
}