#pragma once

#include <xutility>
#include <exception>

class EmptyQueue
	: public std::exception
{};

template <
	class T
>
class TQueue {
public:
	using container_type = TQueue<T>;
	using value_type = T;
	using size_type = size_t;
	using reference = value_type&;
	using const_reference = value_type& const;
private:
	class Elem
	{
	private:
		value_type value;
		Elem * next;
	public:
		Elem(const value_type& val)
			: value(val)
			, next(nullptr)
		{}

		~Elem() {}

		value_type& GetValue()
		{
			return value;
		}

		Elem * GetNext()
		{
			return next;
		}

		void SetNext(Elem * el)
		{
			next = el;
		}
	};
	Elem * first;
public:
	explicit TQueue()
		: first(nullptr)
	{}

	TQueue(const TQueue& other)
	{
		if (other.first == nullptr)
		{
			first = nullptr;
			return *this;
		}
		else
		{
			first = new Elem(other.first->GetValue());
		}

		Elem * cur1 = first;
		Elem * cur2 = other.first;
		while (cur2->GetNext() != nullptr)
		{
			cur1->SetNext(new cur2->GetValue());
			cur1 = cur1->GetNext();
			cur2 = cur2->GetNext();
		}
		return *this;
	}

	~TQueue()
	{
		while (first != nullptr) pop();
	}
	bool Empty() 
	{
	return first == nullptr;
	}
	TQueue<T>& operator=(const TQueue<T>& other)
	{
		delete first;
		if (other.first == nullptr)
		{
			first = nullptr;
			return *this;
		}
		else
		{
			first = new Elem(other.first->GetValue());
		}

		Elem * cur1 = first;
		Elem * cur2 = other.first;
		while (cur2->GetNext() != nullptr)
		{
			cur1->SetNext(new cur2->GetValue());
			cur1 = cur1->GetNext();
			cur2 = cur2->GetNext();
		}
		return *this;
	}

	reference front()
	{
		if (first == nullptr) throw EmptyQueue();

		return first->GetValue();
	}

	const_reference front() const
	{
		if (first == nullptr) throw EmptyQueue();
		return first->GetValue();
	}

	reference back()
	{
		if (first == nullptr) throw EmptyQueue();
		Elem * cur = first;
		while (cur->GetNext() != nullptr)
		{
			cur = cur->GetNext();
		}
		return cur->GetValue();
	}

	const_reference back() const
	{
		if (first == nullptr) throw EmptyQueue();
		Elem * cur = first;
		while (cur->GetNext() != nullptr)
		{
			cur = cur->GetNext();
		}
		return cur->GetValue();
	}

	size_type size() const
	{
		if (first == nullptr)
			return 0;

		size_type result = 1;
		Elem * cur = first;
		while (cur->GetNext() != nullptr)
		{
			result++;
			cur = cur->GetNext();
		}
		return result;
	}

	void push(const T& value)
	{
		if (first == nullptr)
		{
			first = new Elem(value);
			return;
		}
		Elem * cur = first;
		while (cur->GetNext() != nullptr)
		{
			cur = cur->GetNext();
		}
		return cur->SetNext(new Elem(value));
	}

	void pop()
	{
		if (first == nullptr)
			return;
		Elem * temp = first;
		first = first->GetNext();
		delete temp;
	}

	void swap(TQueue<T>& other)
	{
		std::swap(first, other.first);
	}
};
