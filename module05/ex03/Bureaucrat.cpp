#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high, cannot be asigned to Bureacrat (maximum is 1).";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low, cannot be asigned to Bureacrat (minimum is 150).";
}

Bureaucrat::Bureaucrat(void): _name(""), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException): _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_grade = rhs._grade;
	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void) throw(GradeTooHighException)
{
	if (this->_grade < 2)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade(void) throw(GradeTooLowException)
{
	if (this->_grade > 149)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(Form & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signs " << form << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << *this << " cannot sign because " << e.what() << std::endl;
	}
	
}

void Bureaucrat::executeForm(Form const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executs " << form << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << *this << " cannot execute because " << e.what() << std::endl;
	}
	catch(const Form::NotSignedException& e)
	{
		std::cout << *this << " cannot execute because the form is not signed" << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();

	return o;
}


