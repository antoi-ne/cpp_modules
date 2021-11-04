#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("shrubbery creation", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("shrubbery creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other)
{
	*this = other;
}

void ShrubberyCreationForm::applyForm(void) const
{
	std::ofstream of(this->_target + "_shrubbery");
	std::string tree =
		"       ###\n"
		"      #o###\n"
		"    #####o###\n"
		"   #o#\\#|#/###\n"
		"    ###\\|/#o#\n"
		"     # }|{  #\n"
		"       }|{\n";
	of << tree;
	of.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_target = rhs._target;
	return *this;
}
