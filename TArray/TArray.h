#include <iostream>

template< class T,
	std::size_t N
>struct TArray
{

	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;
	value_type Ptr[N];

	TArray() = default;
	~TArray() = default;
	
	TArray(std::initializer_list<T> array)
	{
		size_type i = 0;
		for (auto & e : array) {
			Arr[i] = e;
			++i;
		}
	}
	

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type max_size() const throw()
	{
		return Count;
	}

	iterator begin() const throw()
	{
		return Ptr;
	}

	iterator end() const throw()
	{
		return Ptr + Count;
	}

	reference at(size_type index)
	{
		if (index >= 0 && index < Count)
			return Ptr[index];
		throw std::out_of_range("Error! ");
	}

	const_reference at(size_type index) const
	{
		if (index >= 0 && index < Count)
			return Ptr[index];
		throw std:::out_of_range("Error! ");
	}

	reference operator[](size_type index)
	{
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		return Ptr[index];
	}

	reference front()
	{
		return Ptr[0];
	}

	const_reference front() const
	{
		return Ptr[0];
	}

	reference back()
	{
		return Ptr[Count - 1];
	}

	const_reference back() const
	{
		return Ptr[Count - 1];
	}

	iterator data() throw()
	{
		return Ptr;
	}
	const iterator data() const throw()
	{
		return Ptr;
	}

	void swap(TArray < T, N > & e) throw()
	{
		std::swap(Ptr, e.Ptr);
	}

	void fill(const_reference znch)
	{
		for (size_type i = 0; i < N; ++i)
			Ptr[i] = znch;
	}
};