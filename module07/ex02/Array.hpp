#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Array
{

	public:

		Array(void)
		{
			this->_array = new T[0];
			this->_len = 0;
		}

		Array(unsigned int n)
		{
			this->_array = new T[n];
			this->_len = n;
		}

		Array(Array const & other)
		{
			*this = other;
		}

		virtual ~Array(void)
		{
			delete [] this->_array;
		}

		Array &operator=(Array const & rhs)
		{
			if (this == &rhs)
				return *this;
			delete [] this->_array;
			this->_array = new T[rhs._len];
			this->_len = rhs.len;
			for (size_t i = 0; i < this->_len; i++)
				this->_array[i] = rhs._array[i];
			return *this;
		}

		T &operator[](int i)
		{
			if (i >= this->_len)
				throw std::exception();
			else
				return this->_array[i];
		}

		size_t size(void) const
		{
			return this->_len;
		}

	private:

		T * _array;
		size_t _len;

};

#endif