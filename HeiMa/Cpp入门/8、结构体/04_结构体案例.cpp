#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string name = "";
	int score = 0;
};

struct Teacher
{
	string name = "";
	Student stuArr[5];
};

void completeData(Teacher tArr[], int len)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; ++i)
	{
		tArr[i].name = "teacher_";
		tArr[i].name += nameSeed[i];

		int stuLen = sizeof(tArr[i].stuArr) / sizeof(tArr[i].stuArr[0]);
		for (int j = 0; j < stuLen; ++j)
		{
			tArr[i].stuArr[j].name = "student_";
			tArr[i].stuArr[j].name += nameSeed[j];
			tArr[i].stuArr[j].score = rand() % 100;
		}
	}
}

void printData(Teacher tArr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << "Teacher Name: " << tArr[i].name << endl;
		int stuLen = sizeof(tArr[i].stuArr) / sizeof(tArr[i].stuArr[0]);
		for (int j = 0; j < stuLen; ++j)
		{
			cout << "\tStudent Name: " << tArr[i].stuArr[j].name << " Score: " << tArr[i].stuArr[j].score << endl;
		}
	}
}

int main()
{
	// 老师数组
	Teacher tArr[3];
	
	// 补充数据
	int len = sizeof(tArr) / sizeof(tArr[0]);
	completeData(tArr, len);
	
	// 打印数据
	printData(tArr, len);

	return 0;
}
