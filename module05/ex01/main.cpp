#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "=== Trying to sign form with grade too low ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 140);
			Form f("28C", 139, 1);
			b.signForm(f);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to sign form with exact same grade ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 42);
			Form f("28C", 42, 1);
			b.signForm(f);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to sign form with higher grade ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 1);
			Form f("28C", 10, 1);
			b.signForm(f);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}