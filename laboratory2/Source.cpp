#include <iostream>
#include "TDouble.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	int n = 0;
	do {
		std::cout << "������� ����� ��������� �������:" << std::endl;
		std::cin >> n;
		system("cls");
	} while (n < 0);

	TDouble * doubles = new TDouble[n];
	for (int i = 0; i < n; i++) doubles[i] = TDouble(rand() / 100.);

	double sum = 0;
	int count = 0;
	std::cout << "�����: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << doubles[i].GetValue() << std::endl;
		sum += doubles[i].GetValue();
		count += doubles[i].GetIntCount();
	}

	std::cout << "����� �����: " << sum << std::endl;
	std::cout << "����� ���������� ���� ����� ������: " << count << std::endl;
	system("pause");
	return 0;
}