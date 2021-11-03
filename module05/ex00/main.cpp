
#include "Bureaucrat.hpp"
int main(void)
{
	std::cout << "=== Trying to create a bureaucrat with grade too low ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 151);
			std::cout << b << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to create a bureaucrat with grade too high ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 0);
			std::cout << b << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to create a bureaucrat with valid grade ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 10);
			std::cout << b << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to increment a bureaucrat to 1 ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 2);
			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to increment a bureaucrat to 0 ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 2);
			b.incrementGrade();
			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to decrement a bureaucrat to 150 ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 149);
			b.decrementGrade();
			std::cout << b << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to decrement a bureaucrat to 151 ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 149);
			b.decrementGrade();
			b.decrementGrade();
			std::cout << b << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

