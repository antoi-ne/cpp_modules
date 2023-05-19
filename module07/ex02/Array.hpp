#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Array
{

	public:

		class outOfBoundException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Index out of bounds";
				}
		};

		Array(void)
		{
			this->_array = new T[0]();
			this->_len = 0;
		}

		Array(unsigned int n)
		{
			this->_array = new T[n]();
			this->_len = n;
		}

		Array(Array const & other)
		{
			this->_array = NULL;
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
			if (this->_array)
				delete [] this->_array;
			this->_array = new T[rhs._len]();
			this->_len = rhs._len;
			for (size_t i = 0; i < this->_len; i++)
				this->_array[i] = rhs._array[i];
			return *this;
		}

		T &operator[](int i)
		{
			if (i >= (int)this->_len || i < 0)
				throw outOfBoundException();
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

template<typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &other)
{
	std::cout << "[";
	for (size_t i = 0; i < other.size(); i++)
		os << const_cast<Array<T> &>(other)[i] << ", ";
	std::cout << "]";
	return (os);
}

#endif