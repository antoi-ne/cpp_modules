#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << "Default constructor called for Cat" << std::endl;
}

Cat::Cat(Cat const & other)
{
	std::cout << "Copy constructor called for Cat" << std::endl;
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Destructor called for Cat" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

Cat &Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}