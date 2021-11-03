#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
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

		Bureaucrat(void);
		Bureaucrat(std::string name, int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		Bureaucrat(Bureaucrat const & other);
		virtual ~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const & rhs);

		std::string getName(void) const;

		int getGrade(void) const;

		void incrementGrade(void) throw(GradeTooHighException);
		void decrementGrade(void) throw(GradeTooLowException);

	private:

		std::string const _name;
		int _grade;

};

#endif