#include <iostream>
#include <string>
using namespace std;

bool check_polindrom(string const & a) 
{
	for (int i = 0, k = a.length() - 1; i < a.length() / 2; i++, k--) 
	{
		if (a[i] != a[k]) 
			return false;
	}
	return true;
}

int main()
{
	string str;
	cout << "Enter the word: ";
	cin >> str;
	if (check_polindrom(str))
	{
		cout << "Word is polindrom.";
	}
	else
	{
		cout << "Word is not polindrom";
	}
	system("pause");
	return 0;
}
