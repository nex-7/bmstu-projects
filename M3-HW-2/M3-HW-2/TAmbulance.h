

#ifndef TAMBULANCE_H_
#define TAMBULANCE_H_
#include "TOrganization.h"
namespace GosBudget {

class TAmbulance : public TOrganization {
public:
	TAmbulance();
	virtual ~TAmbulance();

	void addMoney(int);
	int getBudget();
	void lifeCycle(int timestep);
};

} 

#endif 
