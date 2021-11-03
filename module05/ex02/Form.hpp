#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		Form(void);
		Form(std::string name, int sign_grade, int exec_grade) throw(Form::GradeTooHighException, Form::GradeTooLowException);
		Form(Form const & other);
		virtual ~Form(void);

		Form &operator=(Form const & rhs);

		std::string getName(void) const;
		int getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;

		void beSigned(Bureaucrat const & b) throw(GradeTooLowException);

		void execute (Bureaucrat const & executor) const throw(NotSignedException, GradeTooLowException);

	private:

		std::string const _name;
		int const _sign_grade;
		int const _exec_grade;
		bool _signed;

		bool hasPermissionToExecute(Bureaucrat const & executor) const;

		virtual void applyForm(void) const = 0;

};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif