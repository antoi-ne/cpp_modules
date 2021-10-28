#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
}

Cure::Cure(Cure const & other)
{
	*this = other;
}

Cure::~Cure(void)
{
}

AMateria *Cure::clone(void) const
{
	return new Cure();
}

void Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "s wounds *" << std::endl;
}

Cure &Cure::operator=(Cure const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_type = "cure";
	return *this;
}
