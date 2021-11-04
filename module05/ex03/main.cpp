#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "=== Trying to sign and execute ShrubberyCreationForm ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 1);
			Intern intern;
			Form *scf = intern.makeForm("shrubbery creation", "home");

			b.signForm(*scf);
			b.executeForm(*scf);
			delete scf;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to sign and execute PresidentialPardonForm ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 1);
			Intern intern;
			Form *ppf = intern.makeForm("presidential pardon", "Steve");

			b.signForm(*ppf);
			b.executeForm(*ppf);
			delete ppf;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to sign and execute RobotomyRequestForm ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 1);
			Intern intern;
			Form *rrf = intern.makeForm("robotomy request", "Tom");

			b.signForm(*rrf);
			b.executeForm(*rrf);
			delete rrf;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "=== Trying to sign and execute unknown form ===" << std::endl;
	{
		try
		{
			Bureaucrat b("Dave", 1);
			Intern intern;
			Form *uf = intern.makeForm("???", "?");
			(void)uf;
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}