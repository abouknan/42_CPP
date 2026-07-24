#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template<typename T>
class Array
{
private:
    T* _data;
    std::size_t _size;

public:
    Array(): _data(NULL), _size(0) {}

    Array(unsigned int n): _data(NULL), _size(n)
    {
        if (n == 0) { _data = NULL; return; }
        _data = new T[n];
    }

    Array(Array const &other): _data(NULL), _size(other._size)
    {
        if (_size == 0) { _data = NULL; return; }
        _data = new T[_size];
        for (std::size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }

    Array& operator=(Array const &other)
    {
        if (this == &other) return *this;
        delete [] _data;
        _size = other._size;
        if (_size == 0) { _data = NULL; return *this; }
        _data = new T[_size];
        for (std::size_t i = 0; i < _size; ++i)
            _data[i] = other._data[i];
        return *this;
    }

    ~Array() { delete [] _data; }

    T& operator[](std::size_t idx)
    {
        if (idx >= _size) throw std::exception();
        return _data[idx];
    }

    T const & operator[](std::size_t idx) const
    {
        if (idx >= _size) throw std::exception();
        return _data[idx];
    }

    std::size_t size() const { return _size; }
};

#endif
