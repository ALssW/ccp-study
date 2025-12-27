class Student
{
	int* age;

public:
	Student(int* age)
		: age(age)
	{
	}

	~Student()
	{
		age = nullptr;
	};

private:
	Student& operator=(const Student& p);
};

auto Student::operator=(const Student& p) -> Student&
{
	// 默认为浅拷贝，赋值地址，可能会存在重复释放问题
	// age = p.age;

	// 深拷贝
	// 赋值前判断，如果在堆区已有空间则先释放
	if (age != nullptr)
	{
		delete age;
		age = nullptr;
	}

	age = new int(*p.age);
	return *this;
}
