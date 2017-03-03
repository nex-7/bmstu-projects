#include <cstdlib>
#include <iostream>
#include "TVector.h"
#include "TMultiVector.h"

int main()
{
	TVector * vector = new TVector(3, 4);
	TVector * vector_2 = new TMultiVector(3, 4, 12);
	TMultiVector * vector_3 = new TMultiVector(12, 4, 3);

	vector->Print(std::cout);
	vector_2->Print(std::cout);
	vector_3->Print(std::cout);

	system("pause");
	return 0;
}