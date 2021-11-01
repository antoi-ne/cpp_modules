#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice: public AMateria
{

	public:

		Ice(void);
		Ice(Ice const & other);
		virtual ~Ice(void);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);

		Ice &operator=(Ice const & rhs);

};

#endif