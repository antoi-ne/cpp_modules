#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("")
{}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{}

WrongAnimal::WrongAnimal(WrongAnimal const & other)
{
	*this = other;
}

WrongAnimal::~WrongAnimal(void)
{
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