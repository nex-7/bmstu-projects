
#include <iostream>
using namespace std;

#include "TSupervisor.h"

using namespace GosBudget;

int main(int argc, char ** argv)
{
	setlocale(LC_ALL, "Rus");
	string a = (argc > 1) ? (argv[1]) : ("");
	TSupervisor ts(a);
	bool working = true;
	while (working)
	{
		std::string cmd;
		std::cout << "command > ";
		std::cin.clear();
		getline(std::cin, cmd, '\n');
		if (cmd == "exit")
		{
			working = false;
		}
		else
		{
			ts.doCommand(cmd);
		}
	}

}

