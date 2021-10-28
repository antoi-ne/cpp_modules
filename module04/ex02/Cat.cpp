#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	std::cout << "Default constructor called for Cat" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const & other)
{
	std::cout << "Copy constructor called for Cat" << std::endl;
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Destructor called for Cat" << std::endl;
	delete this->_brain;
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
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}