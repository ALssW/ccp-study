#include <iostream>
#include <string>

#include "employee.h"
#include"work.h"

class Manager
{
private:
	Work** workers_;
	int empNum_;

public:
	Manager()
		: workers_(nullptr),
		  empNum_(0)
	{
	}

	void showInfo() const
	{
		if (workers_ == nullptr)
		{
			std::cout << "员工数为空..." << std::endl;
			system("pause");
			return;
		}

		for (int i = 0; i < empNum_; ++i)
		{
			workers_[i]->showInfo();
			workers_[i]->work();
		}
		system("pause");
	}

	void addEmp()
	{

		int newSize = empNum_ + 1;
		Work** newSpaceOfWorks = new Work*[newSize];

		if (workers_ != nullptr)
		{
			for (int i = 0; i < empNum_; i++)
			{
				newSpaceOfWorks[i] = workers_[i];
			}
		}


		int id{};;
		int deptId{};
		std::string name{};

		std::cout << "输入员工id" << std::endl;
		std::cin >> id;

		std::cout << "输入员工姓名" << std::endl;;
		std::cin >> name;

		std::cout << "输入员工部门id" << std::endl;;
		std::cin >> deptId;


		Work* worker = new Employee(id, name, deptId);

		newSpaceOfWorks[newSize - 1] = worker;

		delete[] workers_;
		workers_ = newSpaceOfWorks;
		empNum_ = newSize;

		system("pause");
	}
};
