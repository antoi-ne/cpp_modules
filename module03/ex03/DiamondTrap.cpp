#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("default_name_clap_name"), ScavTrap(), FragTrap(), _name("default_name")
{
	std::cout << "default constructor called for DiamondTrap." << std::endl;
	this->_attack_damage = 30;
	this->_energy_points = 50;
	this->_hitpoints = 100;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "name constructor called for DiamondTrap." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other)
{
	std::cout << "copy constructor called for DiamondTrap." << std::endl;
	*this = other;
}

void DiamondTrap::attack(std::string const & target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::WhoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << " and ClapTrap name: " << this->ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "destructor called for DiamondTrap." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if (this != &rhs)
	{
		this->ClapTrap::_name = rhs.ClapTrap::_name;
		this->_name = rhs._name;
		this->_attack_damage = rhs._attack_damage;
		this->_energy_points = rhs._energy_points;
		this->_hitpoints = rhs._hitpoints;
	}

	return *this;
}
