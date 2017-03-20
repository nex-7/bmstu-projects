#pragma once
#include <iostream>
#include "Tinteger.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	TInteger a(0);
	TInteger b(7);
	std::cout << a << std::endl << b << std::endl;
		a = b;
	std::cout <<"Ïðèðàâíèâàíèå: "<< a << std::endl;
		a += b;
	std::cout << "Ñëîæåíèå: " << a << std::endl;
		a -= b;
	std::cout <<"Âû÷èòàíèå: "<< a << std::endl;
		a *= b;
	std::cout <<"Óìíîæåíèå: "<< a << std::endl;
		a = a / b;
	std::cout <<"Äåëåíèå: " << a << std::endl;
		a /= b;
	std::cout << "Äåëåíèå: " << a << std::endl;
	system("pause");
	return 0;
}
