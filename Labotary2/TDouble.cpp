#include "TDouble.h"

TDouble::~TDouble()
{
}

TDouble::TDouble()
{
	Value = 0;
	String = "0";
}

TDouble::TDouble(double value)
{
	Value = value;
	String = std::to_string(Value);
}

size_t TDouble::GetIntCount()
{
	if ((int)Value == 0) return 1;
	size_t length = 0;
	int value = (int)Value;
	while (value > 0) {
		length++;
		value /= 10;
	}
	return length;
}

double TDouble::GetValue()
{
	return Value;
}

std::ostream & operator<<(std::ostream &out, const TDouble &str)
{
	out << str.Value;
	return out;
}