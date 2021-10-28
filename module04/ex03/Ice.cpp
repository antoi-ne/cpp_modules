#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
}

Ice::Ice(Ice const & other)
{
	*this = other;
}

Ice::~Ice(void)
{
}

AMateria *Ice::clone(void) const
{
	return new Ice();
}

void Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice &Ice::operator=(Ice const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_type = "ice";
	return *this;
}
