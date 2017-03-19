#pragma once
#include <iostream>
#include <exception>
#define MAX_VALUE 2147483647
#define MIN_VALUE -2147483647

class excess : public std::exception
{
public:
	const char * what() const {
		return "Error! Excess";
	}
};
class TInteger
{
	int Data;
public:
TInteger();
TInteger(long long int data);
~TInteger();
bool Check(long long int dat);
TInteger& operator=(const TInteger &rhs);
TInteger& operator=(const long long int data);

bool operator==(const TInteger &rhs);
bool operator==(const long long int data);

TInteger& operator+=(const TInteger &rhs);
TInteger& operator+=(const long long int data);
TInteger& operator-=(const TInteger &rhs);
TInteger& operator-=(const long long int data);
TInteger& operator/=(const TInteger &rhs);
TInteger& operator/=(const long long int data);
TInteger& operator*=(const TInteger &rhs);
TInteger& operator*=(const long long int data);
TInteger& operator%=(const TInteger &rhs);
TInteger& operator%=(const long long int data);
	friend std::ostream & operator<<(std::ostream &, const TInteger &);
};
TInteger operator+(const TInteger &a, const TInteger &b);
TInteger operator+(const TInteger &a, const long long int data);
TInteger operator+(const long long int data, const TInteger &a);

TInteger operator-(const TInteger &a, const TInteger &b);
TInteger operator-(const TInteger &a, const long long int data);
TInteger operator-(const long long int data, const TInteger &a);

TInteger operator*(const TInteger &a, const TInteger &b);
TInteger operator*(const TInteger &a, const long long int data);
TInteger operator*(const long long int data, const TInteger &a);

TInteger operator/(const TInteger &a, const TInteger &b);
TInteger operator/(const TInteger &a, const long long int data);
TInteger operator/(const long long int data, const TInteger &a);

TInteger operator%(const TInteger &a, const TInteger &b);
TInteger operator%(const TInteger &a, const long long int data);
TInteger operator%(const long long int data, const TInteger &a);
