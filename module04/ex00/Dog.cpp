#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(Dog const & other)
{
	std::cout << "Copy constructor called for Cat" << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << "Destructor called for Dog" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

Dog &Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}
