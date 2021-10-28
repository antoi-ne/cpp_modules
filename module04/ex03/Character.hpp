#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{

	public:

		Character(void);
		Character(std::string name);
		Character(Character const & other);
		virtual ~Character(void);

		virtual std::string const & getName() const;
		virtual void equip(AMateria*);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		Character &operator=(Character const & rhs);

	protected:

		std::string _name;
		AMateria *_inventory[4];

};

#endif