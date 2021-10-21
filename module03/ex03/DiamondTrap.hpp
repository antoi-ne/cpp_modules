#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{

	public:

		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & other);
		~DiamondTrap(void);

		using ScavTrap::attack;
		using ScavTrap::takeDamage;
		using ScavTrap::beRepaired;
		using ScavTrap::guardGate;
		using FragTrap::highFivesGuys;

	private:

		std::string _name;

		using FragTrap::_hitpoints;
		using ScavTrap::_energy_points;
		using FragTrap::_attack_damage;

};

#endif
