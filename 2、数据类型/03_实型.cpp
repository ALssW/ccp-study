#include <iostream>
using namespace std;

int main_203()
{
	// 默认情况下，小数被当作 double 类型处理, 需要使用 f 标识
	// 通常只会输出6位有效数字
	float f1 = 3.1415926f;
	cout << "f = " << f1 << endl; // 3.14159

	double d2 = 3.1415926;
	cout << "d = " << d2 << endl; // 3.14159

	// 科学计数法
	float f3 = 3e2f; // 3 * 10 ^ 2
	cout << "f3 = " << f3 << endl; // 300
	
	float f4 = 3e-2f; // 3 * 0.1 ^ 2
	cout << "f4 = " << f4 << endl; // 0.03

	return 0;
}
