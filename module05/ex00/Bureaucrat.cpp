#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high, cannot be asigned to Bureacrat (maximum is 1).";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low, cannot be asigned to Bureacrat (minimum is 150).";
}

Bureaucrat::Bureaucrat(void): _name(""), _note(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int note): _name(name)
{
	this->setNote(note);
}

Bureaucrat::Bureaucrat(Bureaucrat const & other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_note = rhs._note;
	return *this;
}

std::string Bureaucrat::getName(void) const
{

}

void Bureaucrat::setString(std::string name)
{

}

int Bureaucrat::getNote(void) const
{

}

void Bureaucrat::setNote(int note) throw(GradeTooHighException, GradeTooHighException)
{
	if (note > 150)
		throw GradeTooLowException();
	else if (note < 1)
		throw GradeTooHighException();
	else
		this->_note = note;
}

void Bureaucrat::incrementNote(void) throw(GradeTooHighException, GradeTooHighException)
{

}

void Bureaucrat::decrementNote(void) throw(GradeTooHighException, GradeTooHighException)
{

}

