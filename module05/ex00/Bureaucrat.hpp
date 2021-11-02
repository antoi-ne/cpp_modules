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
			virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};

		Bureaucrat(void);
		Bureaucrat(std::string name, int note) throw(GradeTooHighException, GradeTooHighException);
		Bureaucrat(Bureaucrat const & other);
		virtual ~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const & rhs);

		std::string getName(void) const;
		void setString(std::string name);

		int getNote(void) const;
		void setNote(int note) throw(GradeTooHighException, GradeTooHighException);

		void incrementNote(void) throw(GradeTooHighException, GradeTooHighException);
		void decrementNote(void) throw(GradeTooHighException, GradeTooHighException);

		

	private:

		std::string const _name;
		int _note;

};

#endif