#include <iostream>

#include"employee.h"
#include "manager.cpp"


int showMenu()
{
	system("cls");
	std::cout << "*******************************" << std::endl;
	std::cout << "***** 1.添加职工信息 ********" << std::endl;
	std::cout << "***** 2.显示职工信息 ********" << std::endl;
	std::cout << "*******************************" << std::endl;

	int input {};
	std::cin >> input;
	return input;
}

int main_1001 ()
{
	Manager manager;
	while (true)
	{
		
		switch (showMenu())
		{
		case 1:
			manager.addEmp();
			break;
		case 2:
			manager.showInfo();
			break;
		default:
			system("cls");
			break;
		}

		system("cls");
	}

	return 0;
}