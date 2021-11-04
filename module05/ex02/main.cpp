#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "=== Trying to sign and execute ShrubberyCreationForm with grade too low ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 146);
			ShrubberyCreationForm f("home0");
			b.signForm(f);
			b.executeForm(f);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to sign ShrubberyCreationForm with grade too low to execute ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 144);
			ShrubberyCreationForm f("home1");
			b.signForm(f);
			b.executeForm(f);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "=== Trying to sign ShrubberyCreationForm that is not signed ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 144);
			ShrubberyCreationForm f("home3");
			b.executeForm(f);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "=== Trying to sign ShrubberyCreationForm with high enough grade ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 1);
			ShrubberyCreationForm f("home2");
			b.signForm(f);
			b.executeForm(f);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "=== Trying to sign RobotomyRequestForm with high enough grade ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 1);
			RobotomyRequestForm f("Steve");
			b.signForm(f);
			b.executeForm(f);
			b.executeForm(f);
			b.executeForm(f);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "=== Trying to sign PresidentialPardonForm with high enough grade ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 1);
			PresidentialPardonForm f("Steve");
			b.signForm(f);
			b.executeForm(f);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}