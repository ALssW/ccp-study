#include<iostream>

class Person
{
	friend std::ostream& operator<<(std::ostream& cout, const Person& p);
public:
	int age;
	Person();

	Person(int age) : age(age), score() {}

private:
	int score;
};


std::ostream& operator<<(std::ostream& cout, const Person& p)
{
	cout << "age:" << p.age << "score:" << p.score;
	return cout;
}

int main()
{
	Person p1(10);
	Person p2(20);
	std::cout << p1 << p2;
}
