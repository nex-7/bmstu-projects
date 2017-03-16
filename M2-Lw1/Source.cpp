#include <iostream> 
#include <string.h> 
#include "CastException.h" 

int intFromChar(char data) {
	if ('0' <= data && data <= '9')
		return data - '0';
	else
		throw ErrorChar();
}

bool boolFromString(const char * data) {
	if (strcmp(data, "true") == 0 || strcmp(data, "1") == 0)
		return true;
	if (strcmp(data, "false") == 0 || strcmp(data, "0") == 0)
		return false;
	throw ErrorChar();
}

int intFromString(const char* data) {
	bool minus = false;
	int shift = 0;
	int length = 0;

	if (data[0] == '-') {
		minus = true;
		shift = 1;
	}
	while (data[shift + length] != '\0') {
		if (length == 0 && data[shift + length] == '0') {
			shift++;
		}
		else {
			length++;
		}
	}

	int result = 0;
	long long result2 = 0;
	for (int i = (shift + length) - 1; i >= shift; i--) {
		long long plus = intFromChar(data[i]) * pow(10, (shift + length) - i - 1);
		if (minus) {
			plus *= -1;
		}
		result += plus;
		result2 += plus;
		if (result != result2) {
			throw ErrorOver();
		}
	}
	return result;
}

float floatFromString(const char * data) {
	int length1 = 0;
	while (data[length1] != '.') {
		length1++;
	}
	int length2 = 0;
	while (data[length1 + 1 + length2] != '\0') {
		length2++;
	}
	float result = 0;
	for (int i = length1 - 1; i >= 0; i--) {
		result += intFromChar(data[i]) * pow(10, length1 - i - 1);
	}
	for (int i = length1 + 1; i <= length1 + length2; i++) {
		result += intFromChar(data[i]) * pow(10, -1 * (i - length1));
	}
	return result;
}

int main() {
	try {
		bool b;
		b = boolFromString("true");
		std::cout « b « std::endl;
		b = boolFromString("trdddue");
		std::cout « b « std::endl;
	}
	catch (ErrorChar & e) {
		std::cout « "Error char!" « std::endl;
	}

	try {
		int i;
		i = intFromString("2147483647");
		std::cout « i « std::endl;
		i = intFromString("-00002147483648");
		std::cout « i « std::endl;
		i = intFromString("56c78");
		std::cout « i « std::endl;
	}
	catch (ErrorChar & e) {
		std::cout « "Error char!" « std::endl;
	}

	try {
		int i;
		i = intFromString("2147483648");
		std::cout « i « std::endl;
	}
	catch (ErrorOver & e) {
		std::cout « "Error over!" « std::endl;
	}

	try {
		float f;
		f = floatFromString("127.125");
		std::cout « f « std::endl;
		f = floatFromString("4343344.212.11");
		std::cout « f « std::endl;
	}
	catch (ErrorChar & e) {
		std::cout « "Error char!" « std::endl;
	}

	system("pause");
	return 0;
}