#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
	this->_brain = new Brain();
}

Cat::Cat(Cat const & other)
{
	*this = other;
}

Cat::~Cat(void)
{
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
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}