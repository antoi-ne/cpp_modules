#include "Animal.hpp"

Animal::Animal(void): _type("")
{
	std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "String constructor called for Animal" << std::endl;
}

Animal::Animal(Animal const & other)
{
	std::cout << "Copy constructor called for Animal" << std::endl;
	*this = other;
}

Animal::~Animal(void)
{
	std::cout << "Destructor called for Animal" << std::endl;
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
