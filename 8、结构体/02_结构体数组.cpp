#include <iostream>
using namespace std;
#include <string>

struct Student1
{
	// 成员列表
	string name;
	int age;
	int score;
};

int main_802()
{
	// 创建结构体数组
	Student1 stuArr[3] =
	{
		{"张三", 25, 95},
		{"李四", 25, 95},
		{"王五", 25, 95}
	};
	// 访问并修改结构体数组中的元素
	stuArr[2].name = "赵六";
	stuArr[2].age = 20;

	// 遍历结构体
	for (int i = 0; i < 3; i++)
	{
		cout << "name: " << stuArr[i].name << ", 年龄: " << stuArr[i].age << ", 分数: " << stuArr[i].score << endl;
	}

	return 0;
}
