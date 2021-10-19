#include "Fixed.hpp"

int const Fixed::_frac_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "default constructor called" << std::endl;
	this->_raw = 0;
}

Fixed::Fixed(int const i)
{
	std::cout << "int constructor called" << std::endl;
	this->_raw = i * (1 << this->_frac_bits);
}

Fixed::Fixed(float const f)
{
	std::cout << "float constructor called" << std::endl;
	this->_raw = (int)roundf(f * (1 << this->_frac_bits));
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
	return this->_raw;
}

void Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_raw / (float)(1 << this->_frac_bits);
}

int Fixed::toInt(void) const
{
	return (int)roundf((float)this->_raw / (float)(1 << this->_frac_bits));
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_raw = rhs.getRawBits();

	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();

	return o;
}
