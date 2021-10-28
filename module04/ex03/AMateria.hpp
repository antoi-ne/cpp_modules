#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	public:

		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & other);
		virtual ~AMateria(void);

		std::string const & getType(void) const;

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);

		AMateria &operator=(AMateria const & rhs);

	protected:

		std::string _type;

};

#endif