#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int FCount = 0;

	std::ifstream InFile("Test.txt");
	std::string findWord("aaa"); //�������� �����, ���������� �������� ���� ���������
	std::string str;

	while (InFile >> str)
	{
		if (str == findWord)
			++FCount;
		
	}

	std::cout << "���������� ���� " << findWord << " = " << FCount << std::endl;
	InFile.close();

	system("pause");
	return 0;
}