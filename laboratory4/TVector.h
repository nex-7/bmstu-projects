#pragma once

#include <iostream>

class TVector
{
protected:
	double X;
	double Y;
public:
	TVector();

	TVector(double x, double y);

	virtual double Length();

	virtual void Print(std::ostream & stream);
};