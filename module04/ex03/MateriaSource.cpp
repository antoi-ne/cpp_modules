#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for(size_t i = 0; i < 4; i++)
		this->_knowledge[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	*this = other;
}

MateriaSource::~MateriaSource(void)
{
	for(size_t i = 0; i < 4; i++)
	{
		if (this->_knowledge[i] != NULL)
			delete this->_knowledge[i];
	}
}

void MateriaSource::learnMateria(AMateria * m)
{
	size_t i = 0;

	while (i < 4 && this->_knowledge[i] != NULL)
		i++;
	if (i == 4)
		return;
	this->_knowledge[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	size_t	i = 0;

	while (i < 4)
	{
		if (this->_knowledge[i] != NULL && this->_knowledge[i]->getType() == type)
			return this->_knowledge[i]->clone();
		i++;
	}
	return NULL;
}

MateriaSource &MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this == &rhs)
		return *this;
	for(size_t i = 0; i < 4; i++)
	{
		if (this->_knowledge[i] != NULL)
			delete this->_knowledge[i];
	}
	for(size_t i = 0; i < 4; i++)
		this->_knowledge[i] = rhs._knowledge[i]->clone();
	return *this;
}