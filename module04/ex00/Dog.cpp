#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{}

Dog::Dog(Dog const & other)
{
	*this = other;
}

Dog::~Dog(void)
{}

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
