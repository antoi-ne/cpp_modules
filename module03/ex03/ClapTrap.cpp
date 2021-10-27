#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("default_name"), _hitpoints(10), _energy_points(50), _attack_damage(0)
{
	std::cout << "default constructor called for ClapTrap." << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoints(10), _energy_points(50), _attack_damage(0)
{
	std::cout << "name constructor called for ClapTrap." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & other)
{
	std::cout << "copy constructor called for ClapTrap." << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "destructor called for ClapTrap." << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " of dammage" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints == 0)
		std::cout << "ClapTrap " << this->_name << " already had no more hitpoints" << std::endl;
	else if (this->_hitpoints <= amount)
	{
		this->_hitpoints = 0;
		std::cout << "ClapTrap " << this->_name << " lost all his hitpoints" << std::endl;
	}
	else
	{
		this->_hitpoints -= amount;
		std::cout << "ClapTrap " << this->_name << " lost " << amount << " hitpoints and is now at " << this->_hitpoints << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hitpoints += amount;
	std::cout << "ClapTrap " << this->_name << " got back " << amount << " hitpoints and is now at " << this->_hitpoints << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attack_damage = rhs._attack_damage;
		this->_energy_points = rhs._energy_points;
		this->_hitpoints = rhs._hitpoints;
	}

	return *this;
}
