#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
	std::cout << "Default constructor called for WrongCat" << std::endl;
}

WrongCat::WrongCat(WrongCat const & other)
{
	std::cout << "Copy constructor called for WrongCat" << std::endl;
	*this = other;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor called for WrongCat" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}