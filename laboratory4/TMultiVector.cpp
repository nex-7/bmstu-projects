#include "TMultiVector.h"

TMultiVector::TMultiVector() : Z(0)
{
	X = 0;
	Y = 0;
}

TMultiVector::TMultiVector(double x, double y, double z) : Z(z)
{
	X = x;
	Y = y;
}

double TMultiVector::Length()
{
	return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
}

void TMultiVector::Print(std::ostream & stream)
{
	stream << "X: " << X << ", Y: " << Y << ", Z: " << Z << std::endl << "Length: " << Length() << std::endl << std::endl;
}