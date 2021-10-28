#include "Character.hpp"

Character::Character(void): _name("default")
{
	for(size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	for(size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & other)
{
	*this = other;
}

Character::~Character(void)
{
	for(size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

Character &Character::operator=(Character const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_name = rhs._name;
	for(size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	for(size_t i = 0; i < 4; i++)
		this->_inventory[i] = rhs._inventory[i]->clone();
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	size_t i = 0;

	while (i < 4 && this->_inventory[i] == NULL)
		i++;
	if (i == 4)
		return;
	this->_inventory[i] = m;
}

void Character::unequip(int idx)
{
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->_inventory[idx] == NULL)
		return;
	this->_inventory[idx]->use(target);
}
