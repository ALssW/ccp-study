#include <iostream>
using namespace std;
#include <string>

struct Student
{
	// 成员列表
	string name;
	int age;
	int score;
};

int main_0803()
{
	Student stu1 = {"张三", 20, 60};

	// 将指针指向结构体变量
	Student* stuPtr = &stu1;

	// 通过指针访问结构体成员
	// 方式一：使用解引用操作符 *
	cout << "Name: " << (*stuPtr).name << " Age: " << (*stuPtr).age << " Score: " << (*stuPtr).score << endl;
	// 方式二：使用箭头操作符 ->
	cout << "Name: " << stuPtr->name << " Age: " << stuPtr->age << " Score: " << stuPtr->score << endl;

	return 0;
}
