#include <iostream>
using namespace std;

int main_204()
{

	char ch = 'a';
	cout << "ch = " << ch << endl;

	cout << "Size of char: " << sizeof(char) << " 字节" << endl;

	// 错误示范
	// 使用双引号会被当作字符串处理，而不是字符
	// char ch = "a"

	// 使用ASCII码值初始化字符变量
	char ch2 = 65; // A
	cout << "ch2 = " << ch2 << endl; // A

	char ch3 = 97; // a
	cout << "ch2 = " << ch3 << endl; // a

	return 0;
}