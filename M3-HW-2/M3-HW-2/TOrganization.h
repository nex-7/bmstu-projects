

#ifndef TORGANIZATION_H_
#define TORGANIZATION_H_

#include <iostream>

namespace GosBudget {

class TOrganization
{
protected:
	int Budj = 0;
public:
	TOrganization(){};
	virtual void addMoney(int cnt){
		Budj+=cnt;
	};
	virtual int getBudget(){
		return Budj;
	};
	virtual void lifeCycle(int timestep){};
	//Приравнивание к нулю -костыль
	//против "undefined reference to vtable"
	virtual ~TOrganization(){};
};

} 

#endif 
