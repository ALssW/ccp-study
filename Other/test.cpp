#include <iostream>

const int& returnByConstReference(const int& ref)
{
	return ref;
}

int main()
{
	// 案例 1: 直接绑定
	const int& ref1 { 5 }; // 延长生命周期
	std::cout << ref1 << '\n'; // okay

	// 案例 2: 间接绑定
	const int& ref2 { returnByConstReference(5) }; // ref2会绑定到悬空引用
	std::cout << ref2 << '\n'; // 未定义的行为

	return
		0;
}
