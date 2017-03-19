#include"Header.h"

std::ostream & operator<<(std::ostream &out, const TInteger &rhs) {
	out << rhs.Data;
	return out;
}
bool TInteger::Check(long long int data)
{
	if (data > MAX_VALUE || data < MIN_VALUE) throw excess();
	return true;
}
TInteger::TInteger()
{}

TInteger::TInteger(long long int data)
{
	Check(data);
	Data = data;
}

TInteger::~TInteger()
{

}

TInteger operator+(const TInteger &a, const TInteger &b)
{
	return TInteger(a) += TInteger(b);
}

TInteger operator+(const TInteger &a, const long long int data)
{
	return TInteger(a) += data;
}

TInteger operator+(const long long int data, const TInteger &a)
{
	return TInteger(a) += data;
}
TInteger operator-(const TInteger &a, const TInteger &b)
{
	return TInteger(a) -= TInteger(b);
}

TInteger operator-(const TInteger &a, const long long int data)
{
	return TInteger(a) -= data;
}

TInteger operator-(const long long int data, const TInteger &a)
{
	return TInteger(a) -= data;
}
TInteger operator*(const TInteger &a, const TInteger &b)
{
	return TInteger(a) *= TInteger(b);
}

TInteger operator*(const TInteger &a, const long long int data)
{
	return TInteger(a) *= data;
}

TInteger operator*(const long long int data, const TInteger &a)
{
	return TInteger(a) *= data;
}
TInteger operator%(const TInteger &a, const TInteger &b)
{
	return TInteger(a) %= TInteger(b);
}

TInteger operator%(const TInteger &a, const long long int data)
{
	return TInteger(a) %= data;
}

TInteger operator%(const long long int data, const TInteger &a)
{
	return TInteger(a) %= data;
}

TInteger & TInteger::operator=(const TInteger & rhs)
{
	Data = rhs.Data;
	return *this;
}

TInteger & TInteger::operator=(const long long int data)
{
	Check(data);
	Data = data;
	return *this;
}

bool TInteger::operator==(const TInteger & rhs)
{
	if (rhs.Data == this->Data) return true;
	return false;
}

bool TInteger::operator==(const long long int data)
{
	Check(data);
	if (data == this->Data) return true;
	return false;
}

TInteger & TInteger::operator+=(const TInteger & rhs)
{
	long long int Dat = Data + rhs.Data;
	Check(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator+=(const long long int data)
{
	Check(data);
	long long int Dat = Data + data;
	Check(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator-=(const TInteger & rhs)
{
	long long int Dat = Data - rhs.Data;
	Check(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator-=(const long long int data)
{
	Check(data);
	long long int Dat = Data - data;
	Check(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator/=(const TInteger & rhs)
{
	Data /= rhs.Data;
	return *this;
}

TInteger & TInteger::operator/=(const long long int data)
{
	Check(data);
	Data /= data;
	return *this;
}

TInteger & TInteger::operator*=(const TInteger & rhs)
{
	long long int Dat = Data * rhs.Data;
	Check(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator*=(const long long int data)
{
	Check(data);
	long long int Dat = Data * data;
	Check(Dat);
	Data = Dat;
	return *this;
}

TInteger & TInteger::operator%=(const TInteger & rhs)
{
	Data = Data % rhs.Data;
	return *this;
}

TInteger & TInteger::operator%=(const long long int data)
{
	Check(data);
	Data = Data % data;
	return *this;
}

TInteger operator/(const TInteger &a, const TInteger &b) 
{
	return TInteger(a) /= TInteger(b);
}

TInteger operator/(const TInteger &a, const long long int data) 
{
	return TInteger(a) /= data;
}

TInteger operator/(const long long int data, const TInteger &a) 
{
	return TInteger(a) /= data;
};