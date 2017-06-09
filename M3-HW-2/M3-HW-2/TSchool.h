

#ifndef TSCHOOL_H_
#define TSCHOOL_H_

#include "TOrganization.h"

namespace GosBudget {

class TSchool : TOrganization{
public:
	TSchool() {};
	void addMoney(int n);
	int getBudget();
	virtual ~TSchool(){};
	void lifeCycle(int timestep);

};

} 

#endif 
