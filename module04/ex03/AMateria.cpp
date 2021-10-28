#include "AMateria.hpp"

AMateria::AMateria(void): _type("default")
{
}

AMateria::AMateria(std::string const & type): _type(type)
{
}

AMateria::AMateria(AMateria const & other)
{
	*this = other;
}

AMateria::~AMateria(void)
{
}

AMateria &AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

std::string const & AMateria::getType(void) const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses the unknown materia " << this->_type << " on " << target.getName() << " *" << std::endl;
}
