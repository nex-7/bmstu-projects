#pragma once

#include <iostream>

class TVector {
private:
	double * Data;
	int Length;
public:
	// Деструктор
	~TVector();

	// Конструктор по умолчанию
	TVector();

	// Пользовательский консруктор
	TVector(const double * data, int length);

	// Оператор присваивания
	TVector & operator=(const TVector & rhs);

	// Оператор []
	double operator[](size_t index) const;
	double& operator[](size_t index);
};

// Оператор *
TVector operator*(const TVector & a, double b);