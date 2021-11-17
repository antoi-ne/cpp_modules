#include "Span.hpp"

const char * Span::NoSpaceLeftException::what(void) const
{
	return "No space left in span.";
}

Span::Span(void): _size(0), _len(0)
{
	this->_array = new int[0]();
}

Span::Span(unsigned int size): _size(size), _len(0)
{
	this->_array = new int[size]();
}

Span::Span(Span const & other)
{
	this->_array = NULL;
	*this = other;
}

Span::~Span(void)
{
	delete [] this->_array;
}

Span &Span::operator=(Span const & rhs)
{
	if (this == &rhs)
		return *this;
	if (this->_array)
		delete [] this->_array;
	this->_size = rhs._size;
	this->_len = rhs._len;
	this->_array = new int[rhs._size]();
	for (unsigned int i = 0; i < rhs._size; i++)
		this->_array[i] = rhs._array[i];
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_len >= this->_size)
		throw NoSpaceLeftException();
	this->_array[this->_len] = n;
	this->_len++;
}

int Span::shortestSpan(void) const
{
	
}

int Span::longestSpan(void) const
{

}
