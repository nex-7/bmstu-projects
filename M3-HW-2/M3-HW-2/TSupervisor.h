

#ifndef TSUPERVISOR_H_
#define TSUPERVISOR_H_
#include "TSchool.h"
#include "TAmbulance.h"
#include "TMoll.h"
#include "TOrganization.h"

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <locale.h>


namespace GosBudget {

class TSupervisor {
private:
	//Гос. организации
	std::list<TOrganization> orgs;
	//Магазины
	std::list<TMoll> molls;
	//Предыдущие команды
	std::list<std::string> lastCommands;

	//Гос. бюджет
	long megaBudget = 0;
	//Текущее время
	long time = 0;
	//Получено налогов
	long tax = 0;
	//Затрачено на организации
	long donates = 0;
public:
	//Просто ничего не делает
	TSupervisor();
	//Открывает файл и выполняет все команды из него
	//Потом возвращает управление на консоль
	TSupervisor(std::string& filename);
	//Ничего не делает
	virtual ~TSupervisor();
	//Обрабатывает и выполняет команду
	void doCommand(std::string& cmd);
	//Собирает налог с магазинов
	void getAllTax();
	//Переводит деньги из своего бюджета(если они там есть) в гос.организации
	void donateAllOrganizations();
	//Выполняет для каждой организации временной шаг
	void doTimeStep(int timestep);
	//Устанавливает время
	void setTime(int _time);
	//Сохраняет историю команд в файл
	void saveToFile(std::string fname);
	//Печатает сводку
	/*
	 * Текущее время
	 * Количество гос. организаций
	 * Количество магазинов
	 * Сколько дани собрано за все время
	 * Сколько денег передано гос.организациям
	 * Сколько денег осталось
	 * Сколько выполнено команд
	 * */
	void printSummary();
};

} 

#endif 
