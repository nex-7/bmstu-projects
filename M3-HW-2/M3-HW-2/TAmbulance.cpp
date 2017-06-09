
#include "TAmbulance.h"

namespace GosBudget {

TAmbulance::TAmbulance() {
	

}

TAmbulance::~TAmbulance() {
	
}

void TAmbulance::addMoney(int m){
	Budj += m;
}
int TAmbulance::getBudget(){
	return Budj;
}
void TAmbulance::lifeCycle(int timestep){
	Budj -= timestep * 40;
}

} 
