#include "Fixed.hpp"

const int Fixed::_fraction_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "default constructor called" << std::endl;
	this->_number = 0;
}

Fixed::Fixed(Fixed const & other)
{
	std::cout << "copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void)
{
	std::cout << "destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return this->_number;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->_number = raw;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_number = rhs.getRawBits();

	return *this;
}

// std::ostream & operator<<(std::ostream & o, Fixed const & i)
// {
// 	o << i.getRawBits();
// }
