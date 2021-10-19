#include "Fixed.hpp"

int const Fixed::_frac_bits = 8;

Fixed::Fixed(void)
{
	this->_raw = 0;
}

Fixed::Fixed(int const i)
{
	this->_raw = i * (1 << this->_frac_bits);
}

Fixed::Fixed(float const f)
{
	this->_raw = (int)roundf(f * (1 << this->_frac_bits));
}

Fixed::Fixed(Fixed const & other)
{
	*this = other;
}

Fixed::~Fixed(void)
{
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
	if (this != &rhs)
		this->_raw = rhs.getRawBits();

	return *this;
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &	Fixed::operator++(void)
{
	this->_raw++;

	return *this;
}

Fixed &	Fixed::operator--(void)
{
	this->_raw--;

	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);

	this->operator++();
	return copy;
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);

	this->operator--();
	return copy;
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}

Fixed &Fixed::min(Fixed & a, Fixed & b)
{
	return (a > b ? b : a);
}

Fixed &Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed & a, const Fixed & b)
{
	return (a > b ? b : a);
}

const Fixed &Fixed::max(const Fixed & a, const Fixed & b)
{
	return (a > b ? a : b);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();

	return o;
}
