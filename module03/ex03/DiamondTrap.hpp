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

		void attack(std::string const & target);

		void WhoAmI(void);

		DiamondTrap &operator=(DiamondTrap const & rhs);

	private:

		std::string _name;

};

#endif
