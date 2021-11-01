#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure: public AMateria
{

	public:

		Cure(void);
		Cure(Cure const & other);
		virtual ~Cure(void);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);

		Cure &operator=(Cure const & rhs);

};

#endif