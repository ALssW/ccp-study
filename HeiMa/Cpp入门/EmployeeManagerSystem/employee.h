#pragma once
#include <string>

#include "work.h"

class Employee : public Work
{

public:
	Employee(int id, std::string name, int dept_id);

	virtual void work() override;
	
};

