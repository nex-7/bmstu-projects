

#include "TSchool.h"

namespace GosBudget {

void TSchool::addMoney(int n){
		Budj += n;
	};
int TSchool::getBudget(){
		return Budj;
	};
void TSchool::lifeCycle(int timestep){
	Budj -= timestep * 15;
}

} 
