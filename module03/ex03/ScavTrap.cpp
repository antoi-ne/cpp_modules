#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "default constructor called for ScavTrap." << std::endl;
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "name constructor called for ScavTrap." << std::endl;
	this->_hitpoints = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & other)
{
	std::cout << "copy constructor called for ScavTrap." << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "destructor called for ScavTrap." << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " of dammage" << std::endl;
}
void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints == 0)
		std::cout << "ScavTrap " << this->_name << " already had no more hitpoints" << std::endl;
	else if (this->_hitpoints <= amount)
	{
		this->_hitpoints = 0;
		std::cout << "ScavTrap " << this->_name << " lost all his hitpoints" << std::endl;
	}
	else
	{
		this->_hitpoints -= amount;
		std::cout << "ScavTrap " << this->_name << " lost " << amount << " hitpoints and is now at " << this->_hitpoints << std::endl;
	}
}
void ScavTrap::beRepaired(unsigned int amount)
{
	this->_hitpoints += amount;
	std::cout << "ScavTrap " << this->_name << " got back " << amount << " hitpoints and is now at " << this->_hitpoints << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in gatekeeper mode." << std::endl;
}

