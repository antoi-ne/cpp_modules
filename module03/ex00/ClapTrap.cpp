#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "default constructor called." << std::endl;
	this->_hitpoints = 10;
	this->_energy_points = 50;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "name constructor called." << std::endl;
	this->_name = name;
	this->_hitpoints = 10;
	this->_energy_points = 50;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const & other)
{
	std::cout << "copy constructor called." << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "destructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & rhs)
{
	return *this;
}