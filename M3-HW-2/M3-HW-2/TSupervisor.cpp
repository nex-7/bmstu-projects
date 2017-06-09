#include "TSupervisor.h"
#include <fstream>
#include <locale.h>


namespace GosBudget
{
	

std::vector<std::string> commandArgv(std::string & com)
{
	std::vector<std::string> ret;
	size_t i = 0, clen = com.size(), alen = 0;
	while (i < clen)
	{
		switch (com[i])
		{

		case ' ':
		{
			if (i != 0)
			{
				if (com[i - 1] != ' ')
				{
					alen++;
				}
			}
			break;
		}
		default:
		{
			if (i == 0)
			{
				ret.push_back("");
			}
			else
			{
				if (com[i - 1] == ' ')
				{
					ret.push_back("");
				}
			}
			ret[alen] += com[i];
			break;
		}

		}
		i++;
	}
	return ret;
}
size_t commandArgc(std::string & com)
{
	size_t ret = 0;
	size_t i = 0, clen = com.size(); //, alen = 0;
	while (i < clen)
	{
		switch (com[i])
		{

		case ' ':
		{
			break;
		}
		default:
		{
			if (i != 0)
			{
				if (com[i - 1] == ' ')
				{
					ret++;
				}
			}
			else
			{
				ret++;
			}
			break;
		}

		}
		i++;
	}
	return ret;
}

TSupervisor::TSupervisor()
{

}

TSupervisor::TSupervisor(std::string& fname)
{

	try
	{
		std::ifstream file;
		file.open(fname.data());
		if (!file.is_open())
		{
			std::cout << "I cannot open file \"" << fname << "\"\n";
			throw new std::logic_error("Cannot open file\n");
			return;
		}
		std::string s;
		while (!file.eof())
		{
			s.clear();
			getline(file, s);
			doCommand(s);

		}
	} catch (...)
	{
		std::cout << "Error occured in preparation process\n";
	}

}
void TSupervisor::getAllTax()
{
	int tmp = 0;
	for (auto & moll : molls)
	{
		tmp += moll.payTax();

	}
	megaBudget += tmp;
	tax += tmp;
}

void TSupervisor::donateAllOrganizations()
{
	if (megaBudget <= 0)
	{
		return;
	}
	int donation = 100;
	for (auto & org : orgs)
	{
		if (megaBudget >= donation)
		{
			org.addMoney(donation);
			megaBudget -= donation;
			donates += donation;
		}
		else
		{
			break;
		}
	}
}
void TSupervisor::doTimeStep(int timestep)
{
	for (auto & moll : molls)
	{
		moll.lifeCycle(timestep);
	}
	for (auto & org : orgs)
	{
		org.lifeCycle(timestep);
	}
	time += timestep;

}
void TSupervisor::setTime(int _time)
{
	time = _time;
}
void TSupervisor::saveToFile(std::string fname)
{
	try
	{
		std::ofstream f;
		f.open(fname);
		for (auto & command : lastCommands)
		{
			f << command << "\n";
		}
		f.close();
	} catch (...)
	{
		std::cout << "Не получилось сохранить в файл!!!" << std::endl;
	}
}
void TSupervisor::printSummary()
{
	/*
	 * Текущее время
	 * Количество гос. организаций
	 * Количество магазинов
	 * Сколько дани собрано за все время
	 * Сколько денег передано гос.организациям
	 * Сколько денег осталось
	 * Сколько выполнено команд
	 * */
	std::cout << "Time: " << time << std::endl;
	std::cout << "Gos. Organizations: " << orgs.size() << std::endl;
	std::cout << "Molls: " << molls.size() << std::endl;
	std::cout << "Tax accepted: " << tax << std::endl;
	std::cout << "Donated: " << donates << std::endl;
	std::cout << "Money exist: " << megaBudget << std::endl;
	std::cout << "Command cnt " << lastCommands.size() << std::endl;

}
TSupervisor::~TSupervisor()
{

}

void TSupervisor::doCommand(std::string& cmd)
{

	size_t argc = commandArgc(cmd);
	///Посчитали количество аргументов
	if (!argc)
	///Если нет аргументов, то надо просто
	///прекратить выполнение функции
	{
		return;
	}
	///На этой стадии мы точно имеем хотя бы один аргумент.
	auto argv = commandArgv(cmd);
	if (argv[0] == "create")
	{
		
		if (argc > 1)
		{
			
			if (argv[1] == "school")
			{
				TSchool s;
				orgs.push_back(*((TOrganization *)&s));

			}
			else
			{
				if (argv[1] == "ambulance")
				{
					TAmbulance a;
					orgs.push_back(a);
					
				}
				else
				{
					if (argv[1] == "moll")
					{
						TMoll m;
						orgs.push_back(m);
					}
					else
					{
						if (argv[1] == "help")
						{
							std::cout << "COMMAND:\tcreate\n";
							std::cout << "USAGE:\tcreate <args>\n";
							std::cout << "ARGUMENTS:\n";
							std::cout << "\thelp\t-\tprint this help\n";
							std::cout << "\tambulance\t-\tcreate ambulance\n";
							std::cout << "\tschool\t-\tcreate school\n";
							std::cout << "\tmoll\t-\tcreate moll\n";
							return;
						}
						else
						{
							std::cout
									<< "I'm not understand, what are \nyou going to create...\n";
							std::cout
									<< "Try \"create help\" to get help \nfor this command\n";
							return;
						}
					}
				}
			}

		}
		else
		{
			std::cout << "Пользователь, не указал, что именно нужно создать\n";
			return;
		}

	}
	else
	{
		
		if (argv[0] == "help")
		{
			/*
			 * Вывести на экран краткую справку
			 * */
			std::cout << "PROGRAM:\tGosBudget\n";
			std::cout << "USAGE:\t<command> <args>\n";
			std::cout << "COMMANDS:\n";
			std::cout << "\thelp\t-\tprint this help\n";
			std::cout << "\tsave\t-\tsave command history to file\n";
			std::cout << "\tcreate\t-\tcreate something\n";
			std::cout << "\tshow\t-\tshow something\n";
			std::cout << "You can also type \"<command> help\"\n";
			std::cout << "to get help about any command\n";
			return;

		}
		else
		{
			if (argv[0] == "show")
			{
				std::cout << "Ваши действия " << commandArgv << std::endl;

				return;
			}
			else
			{
				if (argv[0] == "step")
				{
					/*
					 * Сделать жизненный цикл и перейти на следующий день
					 * */

				}
				else
				{
					if (argv[0] == "save")
					{
						/*
						 * Сохраниться, если сказано, в какой файл.
						 * Если не сказано - послать.
						 * */
						if (argc > 1)
						{
							if (argv[1] == "help")
							{
								std::cout << "PROGRAM:\tGosBudget\n";
								std::cout << "USAGE:\t<command> <args>\n";
								std::cout << "COMMANDS:\n";
								std::cout << "\thelp\t-\tprint this help\n";
								std::cout << "\tsave\t-\tsave command history to file\n";
								std::cout << "\tcreate\t-\tcreate something\n";
								std::cout << "\tshow\t-\tshow something\n";
								std::cout << "You can also type \"<command> help\"\n";
								std::cout << "to get help about any command\n";
							}
							else
							{
								saveToFile(argv[1]);

							}
						}
						else
						{
							/*
							 * Нам не сказали, куда сохранять.
							 * */
						}
						return;
					}
					else
					{
						/*
						 * Эсли мы до этого дошли - значит
						 * юзверь написал какой-то бред.
						 * Его надо послать.
						 * */

						return;
					}
				}
			}
		}

	}
	/*
	 * Если мы дошли сюда - значит выполнялась
	 * сохраняемая команда. Ее нужно добавить в
	 * соответствующий список.
	 * */
	lastCommands.push_back(cmd);
}
} 

