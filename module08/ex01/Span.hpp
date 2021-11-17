#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Span
{

	public:

		class NoSpaceLeftException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoSpanException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		Span(void);
		Span(unsigned int size);
		Span(Span const & other);
		virtual ~Span(void);

		Span &operator=(Span const & rhs);

		void addNumber(int n);

		int shortestSpan(void) const;
		int longestSpan(void) const;

	private:

		unsigned int _size;
		unsigned int _len;
		int *_array;

};

#endif