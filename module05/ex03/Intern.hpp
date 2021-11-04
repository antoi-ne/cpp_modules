#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{

	public:

		Intern(void);
		Intern(Intern const & other);
		virtual ~Intern(void);

		Intern &operator=(Intern const & rhs);

		Form *makeForm(std::string type, std::string target);

	private:

};

#endif