#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(time(NULL));

	std::cout << "=== Subject example ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "=== inserting range of iterators ===" << std::endl;
	{
		Span sp(10000);
		std::vector<int> vect(10000);

		for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
			*it = std::rand();

		sp.addNumber(vect.begin(), vect.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		try
		{
			sp.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Adding not enough numbers ===" << std::endl;
	{
		Span sp = Span(42);
		sp.addNumber(1);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}