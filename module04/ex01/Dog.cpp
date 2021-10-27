#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	std::cout << "Default constructor called for Dog" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const & other)
{
	std::cout << "Copy constructor called for Dog" << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	std::cout << "Destructor called for Dog" << std::endl;
	delete this->_brain;
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
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}
