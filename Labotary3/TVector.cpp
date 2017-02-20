#include "TVector.h"

TVector::~TVector()
{
	delete[] Data;
}

TVector::TVector()
{
	Length = 0;
	Data = nullptr;
}

TVector::TVector(const double * data, int length)
{
	Length = length;
	Data = new double[Length];
	memcpy(Data, data, Length * sizeof(double));
}

TVector & TVector::operator=(const TVector & rhs)
{
	if (&rhs == this) return *this;
	delete[] Data;
	Length = rhs.Length;
	Data = new double[Length];
	memcpy(Data, rhs.Data, Length * sizeof(double));
	return *this;
}

double TVector::operator[](size_t index) const
{
	return Data[index];
}

double& TVector::operator[](size_t index)
{
	return Data[index];
}

int TVector::Size()
{
	return Length;
}

TVector operator*(TVector & a, double b)
{
	double * resArr = new double[a.Size()];
	for (int i = 0; i < a.Size(); i++) {
		resArr[i] = a[i] * b;
	}
	TVector res(resArr, a.Size());
	delete[] resArr;
	return res;
}