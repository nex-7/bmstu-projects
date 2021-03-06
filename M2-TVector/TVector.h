#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__

#pragma warning(disable:4996)

#include <stdexcept>

class out_of_range :
    public
    std::exception
{
};
using namespace std;
template<typename T>
class TVector
{
public:
    using value_type = T;
    using size_type = size_t;
    using iterator = value_type *;
    using reference = value_type&;
    using const_reference = const value_type&;

private:
    value_type * Ptr;
    size_type Count;
    size_type InternalCapacity;
    int Num(iterator pos)
    {
        for (int i = 0; i < Count; i++)
        {
            if (Ptr[i] == *pos)
                return i;
        }
        return -1;
    }
public:
    TVector()
        : Ptr(nullptr)
        , Count(0)
        , InternalCapacity(0)
    { }

    TVector(size_type capacity)
        : Count(0)
        , InternalCapacity(capacity)
    {
        Ptr = new value_type[InternalCapacity];
    }

    ~TVector()
    {
        delete[] Ptr;
    }

    bool empty() const throw()
    {
        return size() == 0;
    }

    size_type size() const throw()
    {
        return Count;
    }

    size_type capacity() const throw()
    {
        return InternalCapacity;
    }

    iterator begin() const throw()
    {
        return Ptr;
    }

    iterator end() const throw()
    {
        return Ptr + Count;
    }

    void reserve(size_type size)
    {
        if (InternalCapacity > size)
            return;
        TVector copy(*this);
        Ptr = new value_type[size];
        for (size_type i = 0; i < Count; i++)
            Ptr[i] = copy.Ptr[i];
        InternalCapacity = size;
    }

    TVector(const TVector& rhs)
    {
        Count = rhs.Count;
        InternalCapacity = rhs.InternalCapacity;
        Ptr = new value_type[InternalCapacity];
        std::copy(rhs.begin(), rhs.end(), this->begin());
    }

    TVector& operator=(const TVector& rhs)
    {
        if (this == &rhs)
            return *this;
        Count = rhs.Count;
        InternalCapacity = rhs.InternalCapacity;
        std::copy(rhs.begin(), rhs.end(), this->begin());
        return *this;
    }

    void push_back(const value_type& value)
    {
        if (Count >= InternalCapacity)
        {
            if (InternalCapacity == 0)
                reserve(1);
            else
                reserve(InternalCapacity * 2);   
        }
        Ptr[Count] = value;
        Count++;
    }

    reference at(size_type index)
    {
        if (index >= 0 && index < Count)
            return Ptr[index];
        throw std::out_of_range("Error! ");
    }

    value_type at(size_type index) const
    {
        if (index >= 0 && index < Count)
            return Ptr[index];
        throw std::out_of_range("Error! ");
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

    void clear()
    {
        Count = 0;
        InternalCapacity = 0;
        delete[] Ptr;
    }

    void pop_back()
    {
        if (Count == 0)
            throw std::out_of_range("Error! ");
        Count--;
    }

    void swap(TVector& other) throw()
    {
        std::swap(Ptr, other.Ptr);
        std::swap(InternalCapacity, other.InternalCapacity);
        std::swap(Count, other.Count);
    }

    void resize(size_type count, value_type value = value_type())
    {
        if (count > InternalCapacity)
            reserve(count);
        for (int i = Count; i < count; i++)
        {
            Ptr[i] = value;
        }
        Count = count;
    }

    iterator insert(iterator pos, const value_type& value)
    {
        int Pos = *pos;
        if (Pos > Count)
        {
            throw std::out_of_range("Error! ");
        }
        Count++;
        reserve(Count);
        for (int i = Count - 1; i >= Pos; i--)
        {
            Ptr[i] = Ptr[i - 1];
        }
        Ptr[Pos] = value;
        return pos;
    }

    void insert(iterator pos, size_type count, const value_type& value)
    {
        int Pos = *pos;
        if (Pos > Count)
        {
            throw std::out_of_range("Error! ");
        }
        Count += count;
        reserve(Count);
        for (int i = Count - 1; i >= Pos; i--)
        {
            Ptr[i] = Ptr[i - count];
        }
        for (int i = 0; i < count; i++)
        {
            Ptr[i + Pos] = value;
        }
    }

    iterator erase(iterator pos)
    {
        if (pos >= Ptr + Count) throw std::out_of_range("Out of range");
        for (size_type i = 0; pos + i < Ptr + Count - 1; i++)
            *(pos + i) = *(pos + i + 1);
        Count--;
        return pos;
    }

    iterator erase(iterator first, iterator last)
    {
        if (last >= Ptr + Count || first > Ptr + Count)
        {
            throw std::out_of_range("Error! ");
        }
        for (int i = 0; i + last < Ptr + Count; ++i)
        {
            *(i + first) = *(last + i);
        }
        Count -= (last - first);
        return first;
    }
};


#endif // __TVECTOR_INCLUDED__
