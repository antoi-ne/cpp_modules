#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("robotomy request", 72, 45), _target("default")
{
	std::srand(static_cast<int>(std::time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("robotomy request", 72, 45), _target(target)
{
	std::srand(static_cast<int>(std::time(0)));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other)
{
	std::srand(static_cast<int>(std::time(0)));
	*this = other;
}

void RobotomyRequestForm::applyForm(void) const
{
	std::cout << "* drill noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomised!" << std::endl;
	else
		std::cout << "I think we have a problem ..." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_target = rhs._target;
	return *this;
}
