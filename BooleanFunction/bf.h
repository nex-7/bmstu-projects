#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__

#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <exception>

class boolean_function
{
public:
	using value_type = bool;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = typename std::vector<value_type>::iterator;
	using const_iterator = typename std::vector<value_type>::const_iterator;

private:
	std::vector<value_type> func;

	bool xor(bool a, bool b) const
	{
		if (a == b)
			return 0;
		else
			return 1;
	}

	bool checkLen(size_t len)
	{
		size_t i = 0;
		while (len)
		{
			i += len % 2;
			len = len / 2;
		}
		if (i != 1)
			throw std::exception("Error!!!");
		else return true;
	}

	bool comp(const boolean_function & larger, const boolean_function & smaller) const
	{
		auto it = larger.func.begin();
		while (it != larger.func.end())
		{
			auto beg = it;
			for (size_t i = 0; i < smaller.size(); ++i)
				++it;
			if (!std::equal(beg, it, smaller.func.begin()))
				return false;
		}
		return true;
	}
public:

	// возвращает функцию которая равна xn с размерностью dimension
	// пример 1
	// n = 0
	// dimension = 3
	// вернется функция "01010101"
	// пример 2
	// n = 1
	// dimension = 4
	// вернется функция "0011001100110011"
	static boolean_function var(size_t n, size_t dimension)
	{
		boolean_function f(dimension);
		for (size_t i = 0; i + pow(2, n) < f.size(); ++i)
		{
			if (f[i] != 1 && f[i + pow(2, n)] <= f[f.size() - 1])
				f[i + pow(2, n)] = 1;
		}
		return f;
	}

	// тождественный ноль "от dimension переменных"
	static boolean_function zero(size_t dimension)
	{
		std::string var;
		for (size_type i = 0; i < pow(2, dimension); ++i)
			var += '0';
		return boolean_function(var);
	}

	// тождественная единица "от dimension переменных"
	static boolean_function one(size_t dimension)
	{
		std::string var;
		for (size_type i = 0; i < pow(2, dimension); ++i)
			var += '1';
		return boolean_function(var);
	}

	static boolean_function from_anf(std::vector<value_type> v)
	{
		boolean_function Anf(v);
		std::vector<bool> vec = Anf.anf();
		return vec;
	}

	boolean_function() {};

	// задает фунцию тождественного нуля от n переменных
	boolean_function(size_t n)
	{
		for (int i = 0; i < pow(2, n); ++i)
		{
			func.push_back(false);
		}
	}

	// задает фунцию от n переменных. значение равно value
	// пример
	// пусть value = 14, т.е. 0...00001110 в двоичной системе
	// а n = 3
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n)
	{
		for (int i = 0; i < pow(2, n); ++i)
		{

			func.push_back(value % 2);
			value /= 2;
		}
	}

	// пусть table = "01110000"
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table) // 48 = '0'; 49= '1'
	{
		if (log2(table.size()) - (int)log2(table.size()) != 0) 
			throw std::exception("ERROR lenght");
		for (size_t i = 0; i < table.size(); ++i)
		{
			if (table[i] == '0') func.push_back(0);
			else 
				if (table[i] == '1')func.push_back(1);
			else 
				throw;
	}

	// пусть table = {true, false, false, true};
	// тогда АНФ boolean_function будет равна x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		if (checkLen(table.size()))
			func = table;
	}

	boolean_function(const std::initializer_list<bool> vars)
	{
		if (checkLen(vars.size()))
			func = vars;
	}

	boolean_function(const boolean_function& table) : func(table.func)
	{}

	boolean_function& operator=(const boolean_function& rhs)
	{
		func = rhs.func;
		return *this;
	}

	// сложение по модулю 2
	// если разное количество переменных - исключение
	boolean_function& operator += (const boolean_function& rhs)
	{
		if (size() != rhs.size())
			throw std::exception("Error!!!");
		for (size_t i = 0; i < func.size(); ++i)
		{
			func[i] = abs(func[i] - rhs.func[i]);
		}
		return *this;
	}

	// конъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (size() != rhs.size())
			throw std::exception("Error!!!");
		for (int i = 0; i < func.size(); i++)
			func[i] = rhs.func[i] * func[i];
		return *this;

	// дизъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (size() != rhs.size())
			throw std::exception("Error!!!");
		for (int i = 0; i < bf.size(); i++)
			func[i] = func[i] + rhs.func[i] - func[i] * rhs.func[i];
		return *this;
	}

	// побитовое отрицание
	boolean_function operator ~ ()
	{
		func.flip();
		return *this;
	}


	// true если функции равны
	//  иначе false
	bool operator == (const boolean_function& rhs) const
	{
		if (this->size() == rhs.size())
			return func == rhs.func;
		if (this->size() > rhs.size())
			return comp(*this, rhs);
		else 
			return comp(rhs, *this);

	}

	// true если одна функция сравнима и больше или равна rhs
	// false если сравнима и меньше rhs
	// logic_error если фунции не сравнимы
	bool operator >= (const boolean_function& rhs) const
	{
		if (!comparable(*this, rhs))
			throw std::logic_error("Error!!!");
		for (size_t i = 0; i < this->size(); ++i)
		{
			if (func[i] < rhs[i])
				return false;
			if (func[i] > rhs[i])
				return true;
		}
	}

	reference operator[](size_type ind)
	{
		return func[ind];
	}
	const_reference operator[](size_type ind) const
	{
		return func[ind];
	}

	reference at(size_type ind)
	{
		return func.at(ind);
	}
	const_reference at(size_type ind) const
	{
		return func.at(ind);
	}

	iterator begin()
	{
		return func.begin();
	}
	iterator end()
	{
		return func.end();
	}

	const_iterator cbegin() const
	{
		return func.cbegin();
	}
	const_iterator cend() const
	{
		return func.cend();
	}

	// длина столбца функции
	size_type size() const throw()
	{
		return func.size();
	}

	// количество переменных
	size_type dimension() const throw()
	{
		return log2(size());

	}

	// возвращает значение функции
	// пусть boolean_function задает функцию f(x, y, z)
	// тогда функция вернет f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const
	{
		int t = 0;
		for (size_t i = 0; i < vars.size(); ++i)
		{
			t += pow(2, i)*vars[i];
		}
		return this->at(t);

	}

	bool operator()(const std::initializer_list<bool> vars) const
	{
		int t = 0;
		int i = 0;
		for (auto &it : vars)
		{
			t += pow(2, i)*it;
			++i;
		}
		return this->at(t);
	}


	// T(x1, x2, ..., xN) - текущая функция
	// operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const
	{

		if (fs.size() != dimension())
			throw std::exception();
		std::vector <value_type> vec;
		int Size = 0;
		for (int i = 0; i < fs.size(); i++)
		{
			if (fs[i].size() > Size)
				Size = fs[i].size();
		}
		for (int j = 0; j < Size; j++)
		{
			std::vector <value_type> vec1;
			for (int i = 0; i < fs.size(); i++)
			{
				int S = j;
				if (fs[i].size() != Size)
				{
					while (S >= fs[i].size())
						S = S - fs[i].size();
				}
				vec1.push_back(fs[i].bf[S]);
			}
			vec.push_back((*this)(vec1));
		}
		boolean_function res(vec);
		return res;
	}

	boolean_function operator()(const std::initializer_list<boolean_function> vars) const
	{
		std::vector<boolean_function> fs = vars;
		return (*this)(fs);
	}

	bool is_monotone() const
	{
		size_type shift = func.size() / 2;
		while (shift != 0) {
			size_t i = 0;
			while (i + shift <= func.size()) {
				size_t j = shift;
				for (i; j--; ++i) {
					if (func[i] > func[shift + i])
						return false;
				}
				i += shift;
			}
			shift /= 2;
		}
		return true;
	}
	bool is_symmetric() const
	{
		std::vector<value_type> rev(func.size());
		std::reverse_copy(func.begin(), func.end(), rev.begin());
		rev.flip();
		return (func == rev);
	}
	bool is_linear() const
	{
		std::vector<value_type> a = this->anf();
		size_t t = 0;
		for (size_t i = 1; i < a.size(); ++i)
		{
			if (i == pow(2, t))
				++t;
			else 
				if (a[i] == 1)
					return false;
		}
		return true;
	}
	bool is_T1() const
	{
		if (func[size() - 1] == 1)
			return 1;
		return 0;
	}
	bool is_T0() const
	{
		if (func[0] == 0)
			return 1;
		return 0;
	}
	bool is_balanced() const //равновесная ли
	{
		return this->weight() == this->size() / 2;
	}

	size_t weight() const
	{
		size_type result = 0;
		for (size_type i = 0; i < size(); ++i)
			if (func[i] == 1) ++result;
		return result;
		);

	}

	bool is_functionally_complete_system() const
	{
		return ((!is_T0()) && (!is_T1()) && (!is_linear()) && (!is_monotone()) && (!is_symmetric()));
	}

	// Возвращает АНФ функции
	std::vector<value_type> anf() const
	{
		std::vector<value_type> temp;
		std::vector<value_type> tria = func;
		for (size_t i = 0; i < func.size(); ++i)
		{
			temp.push_back(tria[0]);
			for (size_t k = 0; k < tria.size() - 1; ++k)
			{
				tria[k] = xor (tria[k], tria[k + 1]);
			}
			tria.pop_back();
		}
		return temp;
	}
};

// пусть boolean_function представляет из себя функцию "01110000"
// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function& a) // fix
{
	std::vector<bool> ANF;
	std::vector<bool> BUF = func;
	for (size_t i = 0; i < size(); ++i)
	{
		ANF.push_back(BUF[0]);
		for (size_t j = 0; j < size() - 1; ++j)
		{
			if (BUF[j] == BUF[j + 1])
			{
				BUF[j] = false;
				continue;
			}
			BUF[j] = BUF[j] + BUF[j + 1];
		}
	}
	return ANF;
}

boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
	boolean_function newA = a;
	return newA += b
}

boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
	boolean_function newA = a;
	return newA *= b
}

boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
	boolean_function newA = a;
	return newA |= b
}

bool operator != (const boolean_function& a, const boolean_function& b)
{
	return !(a == b);
}


#endif // __BOOLEAN_FUNCTION_INCLUDED__#pragma once
