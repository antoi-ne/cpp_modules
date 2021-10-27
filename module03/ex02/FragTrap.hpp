#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{

	public:

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const & other);
		~FragTrap(void);

		void attack(std::string const & target);

		void highFivesGuys(void);

		FragTrap &operator=(FragTrap const & rhs);

};

#endif
