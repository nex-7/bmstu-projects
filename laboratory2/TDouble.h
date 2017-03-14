#pragma once

#include <iostream>
#include <string>

class TDouble {
private:
	double Value;
	std::string String;
public:
	~TDouble();

	TDouble();

	TDouble(double value);

	size_t GetIntCount();

	double GetValue();

	friend std::ostream & operator<<(std::ostream &, const TDouble &);
};

std::ostream & operator<<(std::ostream &out, const TDouble &str);