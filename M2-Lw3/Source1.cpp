#pragma once
#include <iostream>
#include "Header.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	TInteger a(0);
	TInteger b(7);
	std::cout << a << std::endl << b << std::endl;
		a = b;
	std::cout <<"�������������: "<< a << std::endl;
		a += b;
	std::cout << "��������: " << a << std::endl;
		a -= b;
	std::cout <<"���������: "<< a << std::endl;
		a *= b;
	std::cout <<"���������: "<< a << std::endl;
		a = a / b;
	std::cout <<"�������: " << a << std::endl;
		a /= b;
	std::cout << "�������: " << a << std::endl;
	system("pause");
	return 0;
}