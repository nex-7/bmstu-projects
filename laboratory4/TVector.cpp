#include "TVector.h"

TVector::TVector() : X(0), Y(0)
{}

TVector::TVector(double x, double y) : X(x), Y(y)
{}

double TVector::Length()
{
	return sqrt(pow(X, 2) + pow(Y, 2));
}

void TVector::Print(std::ostream & stream)
{
	stream << "X: " << X << ", Y: " << Y << std::endl << "Length: " << Length() << std::endl << std::endl;
}