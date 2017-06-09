
#include "TMoll.h"

namespace GosBudget {

TMoll::TMoll() {
	

}

TMoll::~TMoll() {
	
}

void TMoll::addMoney(int m){
	Budj += m;
}
int TMoll::getBudget(){
	return Budj;
}
void TMoll::lifeCycle(int timestep){
	Budj -= timestep * 40;
	Budj += (rand()%200)*timestep;
}
int TMoll::payTax(void){
	if(Budj<=0)return 0;
	Budj -= (Budj * 13 )/100;
	return (Budj * 13 )/100;
}

} 
