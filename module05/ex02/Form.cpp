#include "Form.hpp"

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

const char * Form::NotSignedException::what() const throw()
{
	return "Form cannot be executed because it is not signed.";
}

Form::Form(void): _name(), _sign_grade(150), _exec_grade(150), _signed(false)
{}

Form::Form(std::string name, int sign_grade, int exec_grade) throw(Form::GradeTooHighException, Form::GradeTooLowException): _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade > 150)
			throw GradeTooLowException();
	else if (sign_grade < 1)
		throw GradeTooHighException();
	if (exec_grade > 150)
			throw GradeTooLowException();
	else if (exec_grade < 1)
		throw GradeTooHighException();
}

Form::Form(Form const & other): _name(other._name), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade), _signed(other._signed)
{}

Form::~Form(void)
{}

Form &Form::operator=(Form const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_signed = rhs._signed;
	return *this;
}

std::string Form::getName(void) const
{
	return this->_name;
}

int Form::getSigned(void) const
{
	return this->_signed;
}

int Form::getSignGrade(void) const
{
	return this->_sign_grade;
}

int Form::getExecGrade(void) const
{
	return this->_exec_grade;
}

void Form::beSigned(Bureaucrat const & b) throw(GradeTooLowException)
{
	if (this->_sign_grade < b.getGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

bool Form::hasPermissionToExecute(Bureaucrat const & executor) const
{
	if (this->_sign_grade < executor.getGrade())
		return false;
	else
		return true;
}

void Form::execute(Bureaucrat const & executor) const throw(NotSignedException, GradeTooLowException)
{
	if (this->_signed == false)
		throw NotSignedException();
	if (this->hasPermissionToExecute(executor) == false)
		throw GradeTooLowException();
	this->applyForm(executor);
}

std::ostream & operator<<(std::ostream & o, Form const & i)
{
	o << i.getName() << ", Form (" << (i.getSigned()? "SIGNED" : "UNSIGNED") << ", sign grade: " << i.getSignGrade() << ", exec grade: " << i.getExecGrade() << ")";

	return o;
}