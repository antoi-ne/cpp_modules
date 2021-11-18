#include "Span.hpp"

const char *Span::NoSpaceLeftException::what(void) const throw()
{
	return "No space left in span.";
}

const char *Span::NoSpanException::what(void) const throw()
{
	return "Not enough spans (2 min.).";
}

Span::Span(void) : _size(0)
{
}

Span::Span(unsigned int size) : _size(size)
{
}

Span::Span(Span const &other)
{
	*this = other;
}

Span::~Span(void)
{
}

Span &Span::operator=(Span const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_size = rhs._size;
	this->_vect = rhs._vect;
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_vect.size() >= this->_size)
		throw NoSpaceLeftException();
	this->_vect.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	this->_vect.insert(this->_vect.end(), begin, end);
}

int Span::shortestSpan(void) const
{
	if (this->_vect.size() < 2)
		throw NoSpanException();

	std::vector<int> copy(this->_vect);
	std::sort(copy.begin(), copy.end());

	int span = INT_MAX;

	for (std::vector<int>::iterator it = copy.begin(); it != copy.end() && it + 1 != copy.end(); it++)
	{
		int x = *(it + 1) - *it;
		if (x < span)
			span = x;
	}

	return span;
}

int Span::longestSpan(void) const
{
	if (this->_vect.size() < 2)
		throw NoSpanException();

	int max = *std::max_element(this->_vect.begin(), this->_vect.end());
	int min = *std::min_element(this->_vect.begin(), this->_vect.end());

	return max - min;
}
