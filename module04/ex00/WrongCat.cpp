#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{}

WrongCat::WrongCat(WrongCat const & other)
{
	*this = other;
}

WrongCat::~WrongCat(void)
{}

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