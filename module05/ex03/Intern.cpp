#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern const & other)
{
	*this = other;
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

Form *Intern::makeForm(std::string type, std::string target)
{
	Form *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	std::string refs[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *ret = NULL;

	for(size_t i = 0; i < 3; i++)
	{
		if (refs[i] == type)
		{
			ret = forms[i];
		}
		else
			delete forms[i];
	}
	if (ret != NULL)
		std::cout << "Intern creates " << *ret << std::endl;
	else
		std::cout << "Intern does not know this form type" << std::endl;
	return ret;
}
