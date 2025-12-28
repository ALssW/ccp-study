#pragma once
#include <iostream>
#include <string>

class Work
{
public:

	int id;
	std::string name;
	int dept_id;

	virtual void work() = 0;

	void showInfo() const
	{
		std::cout << "员工编号：" << id
			<< " 员工姓名：" << name
			<< " 部门编号：" << dept_id << std::endl;
	};

};
