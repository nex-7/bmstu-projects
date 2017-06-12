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
		else return 1;
	}

	bool checkLength(size_t len)
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
		boolean_function z(dimension);
		return z;
	}

	// тождественная единица "от dimension переменных"
	static boolean_function one(size_t dimension)
	{
		boolean_function on(dimension);
		~on;
		return on;
	}

	static boolean_function from_anf(std::vector<value_type> v)
	{
		std::vector<value_type> temp;
		std::vector<value_type> tria = v;
		for (size_t i = 0; i < v.size(); ++i)
		{
			temp.push_back(tria[0]);
			for (size_t k = 0; k < tria.size() - 1; ++k)
			{
				if (tria[k] == tria[k + 1])
					tria[k] = 0;
				else tria[k] = 1;
			}
			tria.pop_back();
		}
		boolean_function t(temp);
		return t;
	}

	boolean_function() = default;

	// задает фунцию тождественного нуля от n переменных
	boolean_function(size_t n)
	{
		func.resize(pow(2, n));
		std::fill(func.begin(), func.end(), 0);
	}

	// задает фунцию от n переменных. значение равно value
	// пример
	// пусть value = 14, т.е. 0...00001110 в двоичной системе
	// а n = 3
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n)
	{
		while (value)
		{
			func.insert(func.begin(), (value % 2));
			value = value / 2;
		}
		while (func.size() < pow(2, n))
		{
			func.insert(func.begin(), 0);
		}
		std::reverse(func.begin(), func.end());
	}

	// пусть table = "01110000"
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table) // 48 = '0'; 49= '1'
	{
		size_t dim = log2(table.length());
		if (pow(2, dim) != table.length())
			throw std::exception("Error!!!");
		for (auto i : table)
		{
			if (i == '0') func.push_back(false);
			else 
				if (i == '1') func.push_back(true);
			else 
				throw std::exception("Error!!!");
		}
	}

	// пусть table = {true, false, false, true};
	// тогда АНФ boolean_function будет равна x + y + 1
	boolean_function(const std::vector<value_type>& table)
	{
		size_t dim = log2(table.size());
		if (pow(2, dim) != table.size()) throw std::exception("Error!!!");
		for (auto i : table)
		{
			func.push_back(i);
		}
	}

	boolean_function(const std::initializer_list<bool> vars)
	{
		size_t dim = log2(vars.size());
		if (pow(2, dim) != vars.size()) 
			throw std::exception("Error!!!");
		for (auto i : vars)
		{
			func.push_back(i);
		}
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
		if (this->size() != rhs.size())
			throw std::exception("Error!!!");
		for (size_t i = 0; i < this->size(); ++i)
		{
			func[i] = func[i] ^ rhs.func[i];
		}
		return *this;
	}

	// конъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (this->size() != rhs.size())
			throw std::exception("Error!!!");
		for (size_t i = 0; i < this->size(); ++i)
		{
			func[i] = func[i] & rhs.func[i];
		}
	}

	// дизъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (this->size() != rhs.size())
			throw std::exception("Error!!!");
		for (size_t i = 0; i < this->size(); ++i)
		{
			func[i] = func[i] | rhs.func[i];
		}
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
		size_t n;
		if (size() < rhs.size()) {
			n = size();
		}
		else {
			n = rhs.size();
		}
		for (size_t i = 0; i < n; ++i) {
			if (func[i] != rhs.func[i]) {
				return false;
			}
		}
		return true;

	}

	// true если одна функция сравнима и больше или равна rhs
	// false если сравнима и меньше rhs
	// logic_error если фунции не сравнимы
	bool operator >= (const boolean_function& rhs) const
	{
		if (this->size() == rhs.size())
		{
			size_t t = 0;
			for (size_t i = 0; i < func.size(); ++i)
			{
				if (func[i] >= rhs.func[i])
					++t;
			}
			if (t == func.size())
				return true;
			else
			{
				t = 0;
				for (size_t i = 0; i < func.size(); ++i)
				{
					if (func[i] <= rhs.func[i])
						++t;
				}
			}
			if (t == func.size())
				return false;
		}
		throw std::exception("Error!!!");
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
		return log2(func.size());
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
		std::vector<boolean_function> tmp = fs;
		std::vector<size_t> sizes;
		for (auto it = fs.begin(); it != fs.end(); ++it)
			sizes.push_back(it->size());
		size_t max = *std::max_element(sizes.begin(), sizes.end(), [](size_t a, size_t b) {return a < b; });
		for (size_t i = 0; i < sizes.size(); ++i)
		{
			while (sizes[i] != max)
			{
				tmp[i].func.resize(2 * sizes[i]);
				for (size_t k = 0; k < sizes[i]; ++k)
					tmp[i].func[k + sizes[i]] = tmp[i].func[k];
				sizes[i] = tmp[i].size();
			}

		}
		std::vector<value_type> g;

		for (size_t j = 0; j < max; ++j)
		{
			std::vector<value_type> temp;
			for (size_t i = 0; i < tmp.size(); ++i)
			{
				temp.push_back(tmp.at(i).at(j));
			}
			g.push_back((*this)(temp));
		}
		boolean_function G(g);
		return G;
	}

	boolean_function operator()(const std::initializer_list<boolean_function> vars) const
	{
		std::vector<boolean_function> fs = vars;
		return (*this)(fs);
	}

	bool is_monotone() const
	{
		if (func.size() == 0)
			throw std::exception("");
		for (size_t i = 0; i < func.size() - 1; ++i)
			if (func[i] > func[i + 1])
				return false;
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
		std::vector<value_type> a = anf();
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
		auto it = func.end();
		--it;
		return (*it == 1);
	}
	bool is_T0() const
	{
		return (*(func.begin()) == 0);
	}
	bool is_balanced() const //равновесная ли
	{
		return this->weight() == this->size() / 2;
	}

	size_t weight() const
	{
		size_t result = 0;
		for (size_t i = 0; i < func.size(); ++i)
		{
			if (func[i] == true)
			{
				++result;
			}
		}
		return result;
	}

	bool is_functionally_complete_system() const
	{
		if (!is_T0() && !is_T1() && !is_linear() && !is_monotone() && !is_symmetric()) 
			return true;
		else 
			return false;
	}

	// Возвращает АНФ функции
	std::vector<value_type> anf() const
	{
		std::vector<value_type> func(func);
		size_type i = 1;
		while (i < func.size())
		{
			std::vector<value_type> tmp;
			size_type j = 0;
			while (j < func.size())
			{
				size_type k = 0;
				while (k < i)
				{
					if (!((j / i) % 2))  tmp.push_back(func[k + j]);
					else   tmp.push_back(func[k - i + j] ^ func[k + j]);
					++k;
				}
				j += i;
			}
			func = tmp;
			i *= 2;
		}
		return func;
	}


};

// пусть boolean_function представляет из себя функцию "01110000"
// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function & obj)
{
	std::vector<bool> an = obj.anf();
	std::string polynom;
	size_t dim = obj.dimension();
	for (size_t i = 0; i < obj.size(); ++i)
	{
		if (obj[i] == 1)
		{
			if (i == 0)
				polynom += '1';
			std::vector<int> t;
			size_t k = i;
			while (k)
			{
				t.insert(t.begin(), (k % 2));
				k = k / 2;
			}
			for (auto it = t.begin(); it != t.end(); ++it)
			{
				if ((*it != 0))
				{
					polynom += 'x';
					polynom += std::to_string(*it);
				}
			}
			polynom += " + ";
		}
	}
	polynom.erase(polynom.size() - 4, 3);
	return polynom;
}

boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
	return boolean_function(a) += boolean_function(b);
}

boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
	return boolean_function(a) *= boolean_function(b);
}

boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
	return boolean_function(a) |= boolean_function(b);
}

bool operator != (const boolean_function& a, const boolean_function& b)
{
	return !(a == b);
}


#endif // __BOOLEAN_FUNCTION_INCLUDED__#pragma once