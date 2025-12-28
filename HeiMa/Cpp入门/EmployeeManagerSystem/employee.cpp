#include "employee.h"

#include <iostream>

Employee::Employee(int id, std::string name, int dept_id)
{
	this->id = id;
	this->name = name;
	this->dept_id = dept_id;
}

void Employee::work()
{
	std::cout << this->name << " is working..." << std::endl;
}
