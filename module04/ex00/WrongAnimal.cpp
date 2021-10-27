#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("")
{
	std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "String constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & other)
{
	std::cout << "Copy constructor called for WrongAnimal" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor called for WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->_type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "* weird animal sound *" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}