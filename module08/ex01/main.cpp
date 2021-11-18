#include "Span.hpp"

int main(void)
{
	Span s(10);
	s.addNumber(17);
	s.addNumber(8);
	s.addNumber(2);
	s.addNumber(17);
	std::cout << s.longestSpan() << std::endl;
	std::cout << s.shortestSpan() << std::endl;
	return 0;
}