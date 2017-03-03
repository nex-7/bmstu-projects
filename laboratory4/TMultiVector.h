#pragma once

#include "TVector.h"

class TMultiVector : public TVector
{
protected:
	double Z;
public:
	TMultiVector();

	TMultiVector(double x, double y, double z);

	virtual double Length();

	virtual void Print(std::ostream & stream);
};