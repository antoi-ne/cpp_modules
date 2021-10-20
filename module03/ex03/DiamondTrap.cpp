#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap()
{
	std::cout << "default constructor called for DiamondTrap." << std::endl;
	this->_hitpoints = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name)
{
	std::cout << "name constructor called for DiamondTrap." << std::endl;
	this->_hitpoints = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other)
{
	std::cout << "copy constructor called for DiamondTrap." << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "destructor called for DiamondTrap." << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	std::cout << "DiamondTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " of dammage" << std::endl;
}
void DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints == 0)
		std::cout << "DiamondTrap " << this->_name << " already had no more hitpoints" << std::endl;
	else if (this->_hitpoints <= amount)
	{
		this->_hitpoints = 0;
		std::cout << "DiamondTrap " << this->_name << " lost all his hitpoints" << std::endl;
	}
	else
	{
		this->_hitpoints -= amount;
		std::cout << "DiamondTrap " << this->_name << " lost " << amount << " hitpoints and is now at " << this->_hitpoints << std::endl;
	}
}
void DiamondTrap::beRepaired(unsigned int amount)
{
	this->_hitpoints += amount;
	std::cout << "DiamondTrap " << this->_name << " got back " << amount << " hitpoints and is now at " << this->_hitpoints << std::endl;
}

void DiamondTrap::highFivesGuys(void)
{
	std::cout << "DiamondTrap " << this->_name << " wants to high-five his teammates!" << std::endl;
}

