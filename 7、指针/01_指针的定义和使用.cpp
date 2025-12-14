#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	// 定义指针: 数据类型 * 指针变量名;
	int* p;
	// 使用指针变量: 指针变量名 = & 变量名;
	p = &a;

	cout << " sizeof " << sizeof(p); << endl;

	cout << "a的值为: a = " << a << endl;
	cout << "a的地址为: &a = " << &a << endl;
	cout << "p指向的地址为: p = " << p << endl;
	// *p  表示解引用指针变量p, 获取p指向地址存储的值
	cout << "p解引用的值为: *p = " << *p << endl;
	cout << "p的地址为: &p = " << &p << endl;

	cout << "=========================" << endl;

	*p = 1000;
	cout << "*p = 1000; 之后" << endl;
	cout << "a的值为: a = " << a << endl;
	cout << "a的地址为: &a = " << &a << endl;
	cout << "p指向的地址为: p = " << p << endl;
	cout << "p解引用的值为: *p = " << *p << endl;
	cout << "p的地址为: &p = " << &p << endl;

	return 0;
}