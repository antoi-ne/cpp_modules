#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap()
{
	std::cout << "default constructor called for DiamondTrap." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "name constructor called for DiamondTrap." << std::endl;
	this->_attack_damage = this->FragTrap::_attack_damage;
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
