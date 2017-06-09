

#ifndef TMOLL_H_
#define TMOLL_H_
#include "TOrganization.h"
namespace GosBudget {

class TMoll: public TOrganization {

public:
	TMoll();
	virtual ~TMoll();
	void addMoney(int);
	int getBudget();
	void lifeCycle(int timestep);
	int payTax(void);


};

} 

#endif 
