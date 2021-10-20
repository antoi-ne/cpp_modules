#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "default constructor called for FragTrap." << std::endl;
	this->_hitpoints = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "name constructor called for FragTrap." << std::endl;
	this->_hitpoints = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const & other)
{
	std::cout << "copy constructor called for FragTrap." << std::endl;
	*this = other;
}

FragTrap::~FragTrap(void)
{
	std::cout << "destructor called for FragTrap." << std::endl;
}

void FragTrap::attack(std::string const & target)
{
	std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " of dammage" << std::endl;
}
void FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints == 0)
		std::cout << "FragTrap " << this->_name << " already had no more hitpoints" << std::endl;
	else if (this->_hitpoints <= amount)
	{
		this->_hitpoints = 0;
		std::cout << "FragTrap " << this->_name << " lost all his hitpoints" << std::endl;
	}
	else
	{
		this->_hitpoints -= amount;
		std::cout << "FragTrap " << this->_name << " lost " << amount << " hitpoints and is now at " << this->_hitpoints << std::endl;
	}
}
void FragTrap::beRepaired(unsigned int amount)
{
	this->_hitpoints += amount;
	std::cout << "FragTrap " << this->_name << " got back " << amount << " hitpoints and is now at " << this->_hitpoints << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " wants to high-five his teammates!" << std::endl;
}

