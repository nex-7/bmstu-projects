#include <iostream>
#include <thread>
#include "InfInt.h"
#include <exception>

void fct(int num, InfInt * result)
{
	(*result) = 1;
	for (int i = 2; i <= num; i++)
		(*result) = (*result) * i;
}

InfInt C(int n, int k) {
	if (k == 0 || n == 0) 
		return 0;
	InfInt result1, result2, result3;

	std::thread one(fct, n, & result1);
	std::thread two(fct, k, & result2);
	std::thread three(fct, (n - k), & result3);

	one.join();
	two.join();
	three.join();
	return result1 / (result2 * result3);
}

int main() {
	InfInt cnk;
	cnk = C(5, 2);
	std::cout << cnk << std::endl;
	system("pause");
	return 0;
}