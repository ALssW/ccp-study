#include <iostream>
using namespace std;
#include <string>


// 定义结构体
struct Student1
{
	// 成员列表
	string name;
	int age;
	int score;
} stu3; // 创建方式三：定义结构体的同时创建变量 s3

int main_801()
{
	// 创建方式一：
	struct Student1 stu1;
	// struct 可省略
	// Student1 stu1;
	stu1.name = "张三";
	stu1.age = 20;
	stu1.score = 90;

	cout << "Name: " << stu1.name << ", Age: " << stu1.age << ", Score: " << stu1.score << '\n';

	// 创建方式二：
	Student1 stu2 = {"李四", 25, 95};
	cout << "Name: " << stu2.name << ", Age: " << stu2.age << ", Score: " << stu2.score << '\n';

	// 在定义结构体的同时创建变量
	stu3.name = "王五";
	stu3.age = 22;
	stu3.score = 88;
	cout << "Name: " << stu3.name << ", Age: " << stu3.age << ", Score: " << stu3.score << '\n';

	return 0;
}
