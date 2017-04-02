#ifndef __SCOPED_PTR__
#define __SCOPED_PTR__

template<class T>
class TScopedPtr
{
private:
	T * Ptr;
public:
	TScopedPtr(TScopedPtr const &) = delete;
	TScopedPtr & operator=(TScopedPtr const &) = delete;

	explicit TScopedPtr(T * p = nullptr)
	{
		Ptr = p;
	}

	~TScopedPtr() 
	{
		delete Ptr;
	}

	void reset(T * p = nullptr) 
	{
		if (p == Ptr) return;
		delete Ptr;
		Ptr = p;
	}

	T & operator*() const 
	{
		return *Ptr;
	}

	T * operator->() const 
	{
		return Ptr;
	}

	T * get() const throw() 
	{
		return Ptr;
	}

	void swap(TScopedPtr & b) throw() 
	{
		std::swap(Ptr, b.Ptr);
	}

	bool operator! () const throw() 
	{
		if (Ptr == nullptr) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	explicit operator bool() const throw() 
	{
		if (Ptr != nullptr) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
};

template<class T>
inline bool operator==(TScopedPtr<T> const & p, std::nullPtrt) throw() 
{
	if (p.get() == nullptr) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template<class T>
inline bool operator==(std::nullPtrt, TScopedPtr<T> const & p) throw() 
{
	if (p.get() == nullptr) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template<class T>
inline bool operator!=(TScopedPtr<T> const & p, std::nullPtrt) throw() 
{
	if (p.get() != nullptr)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template<class T>
inline bool operator!=(std::nullPtrt, TScopedPtr<T> const & p) throw() 
{
	if (p.get() != nullptr)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

template<class T>
inline void swap(TScopedPtr<T> & a, TScopedPtr<T> & b) throw() 
{
	a.swap(b);
}

// get_pointer(p) is a generic way to say p.get()
template<class T>
inline T * get_pointer(TScopedPtr<T> const & p) throw() 
{
	return p.get();
}

#endif // __SCOPED_PTR__
