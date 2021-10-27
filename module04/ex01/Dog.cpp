#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
	this->_brain = new Brain();
}

Dog::Dog(Dog const & other)
{
	*this = other;
}

Dog::~Dog(void)
{
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
