#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <Weapon.hpp>

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;

		HumanB();

	public:
		HumanB(std::string name);
		~HumanB();

		void setWeapon(Weapon &weapon);
		void attack() const;
};

#endif