#include "Animal.hpp"

Animal::Animal(void): _type("")
{}

Animal::Animal(std::string type): _type(type)
{}

Animal::Animal(Animal const & other)
{
	*this = other;
}

Animal::~Animal(void)
{
}

Animal &Animal::operator=(Animal const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

std::string Animal::getType(void) const
{
	return this->_type;
}

void Animal::makeSound(void) const
{
	std::cout << "* weird animal sound *" << std::endl;
}
