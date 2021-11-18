#include "Span.hpp"

const char * Span::NoSpaceLeftException::what(void) const throw()
{
	return "No space left in span.";
}

const char * Span::NoSpanException::what(void) const throw()
{
	return "Not enough spans (2 min.).";
}

Span::Span(void): _size(0)
{}

Span::Span(unsigned int size): _size(size)
{}

Span::Span(Span const & other)
{
	*this = other;
}

Span::~Span(void)
{}

Span &Span::operator=(Span const & rhs)
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

int Span::shortestSpan(void)
{
	if (this->_vect.size() < 2)
		throw NoSpanException();

	std::vector<int>::iterator it1;
	std::vector<int>::iterator it2;

	int span = INT_MAX;

	for(it1 = this->_vect.begin(); it1 != this->_vect.end(); it1++)
	{
		int ref = *it1;

		for(it2 = this->_vect.begin(); it2 != this->_vect.end(); it2++)
		{
			if (std::distance(this->_vect.begin(), it1) == std::distance(this->_vect.begin(), it2))
				continue;

			long long diff = ref;
			diff = std::abs(diff - *it2);
			if (diff < span)
				span = diff;
		}
	}

	return span;
}

int Span::longestSpan(void)
{
	if (this->_vect.size() < 2)
		throw NoSpanException();

	int max = *std::max_element(this->_vect.begin(), this->_vect.end());
	int min = *std::min_element(this->_vect.begin(), this->_vect.end());

	return max - min;
}
