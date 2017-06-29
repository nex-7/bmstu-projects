#include <iostream>

#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <numeric>

enum Grade
{
	F = 1,
	D,
	C,
	B,
	A
};

struct Student
{
	std::string FIO;
	std::string Group;
	std::map<std::string, Grade> Grades;
};

std::vector<Student> LoadStudents()
{
	return{
		{
			"Anna", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::A },
				{ "english", Grade::A },
				{ "dutch", Grade::B },
			}
		},
		{
			"Petr", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Vova", "G1",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
			}
		},
		{
			"Vasya", "G3",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Anton", "G4",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "dutch", Grade::C },
				{ "cs", Grade::C },
			}
		},
		{
			"Masha", "G2",
			{
				{ "math", Grade::A },
			}
		},
		{
			"Sasha", "G6",
			{
				{ "english", Grade::F },
				{ "russian", Grade::F },
				{ "dutch", Grade::F },
			}
		},
		{
			"Jeka", "G2",
			{
				{ "english", Grade::A },
			}
		},
		{
			"Sveta", "G3",
			{
			}
		}
	};
}

struct FindStudentGroup
{
	std::string neededGroup;
	bool operator()(const Student& s) const
	{
		return s.Group == neededGroup;
	}
};

struct PrinterStudent {
	std::string neededGroup;

	void operator()(const Student &s) const {
		if (neededGroup == s.Group)
			std::cout << s.FIO << " studies in " << s.Group << std::endl;
	}
};
struct GradeEqual
{
	Grade grade = Grade::A;

	bool operator()(const std::pair<std::string, Grade> & el) const
	{
		return el.second == grade;
	}
};
struct BestMath {
	std::string fio;
	int grade = 0;

	void operator()(Student& rhs) 
	{
		auto it = rhs.Grades.find("math");
		if (it != rhs.Grades.end()) 
		{
			if (grade == 0 || rhs.Grades.at("math")>grade) 
			{
				fio = rhs.FIO;
				grade = rhs.Grades.at("math");
			}
		}
	}
};
struct FindGroup {
	std::multimap<std::string, Student> MAP;

	void operator()(Student& rhs) {
		MAP.insert(std::make_pair(rhs.Group, rhs));
	}
};

struct Literature {

	void operator()(Student &student) {
		size_t summ = 0;
		for (auto it = student.Grades.begin(); it != student.Grades.end(); ++it) {
			summ += it->second;
		}
		if (student.Grades.size() == 0) {
			student.Grades["literature"] = Grade(1);
		}
		else
			student.Grades["literature"] = (Grade)(int(ceil(summ / student.Grades.size())));
	}
};
struct Dutch {
	void operator()(Student &a) {
		auto s = a.Grades.find("dutch");
		if (s != a.Grades.end()) {
			std::cout << a.FIO << "Marks: " << s->second << std::endl;
		}
		else {
			std::cout << a.FIO << "Doesn't study dutch " << std::endl;
		}
	}
};



int main() 
{
	std::vector<Student> students = LoadStudents();

	auto it = std::for_each(students.begin(), students.end(), BestMath());
	std::cout << it.fio << std::endl;


	auto Max = std::max_element(students.begin(), students.end(),
		[](const Student & a, const Student & b)
	{
		return a.Grades.size() < b.Grades.size();
	});
	std::cout << Max->FIO << std::endl;

	auto Sor = std::for_each(students.begin(), students.end(), FindGroup());

	std::for_each(students.begin(), students.end(), PrinterStudent{ "G7" });

	std::for_each(students.begin(), students.end(), Dutch());

	std::for_each(students.begin(), students.end(), Literature());
	system("pause");
	return 0;
};
