#pragma once

#include <iostream>

class TVector {
private:
	double * Data;
	int Length;
public:
	// ����������
	~TVector();

	// ����������� �� ���������
	TVector();

	// ���������������� ����������
	TVector(const double * data, int length);

	// �������� ������������
	TVector & operator=(const TVector & rhs);

	// �������� []
	double operator[](size_t index) const;
	double& operator[](size_t index);
};

// �������� *
TVector operator*(const TVector & a, double b);