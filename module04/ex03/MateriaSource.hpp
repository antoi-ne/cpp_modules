#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{

	public:

		MateriaSource(void);
		MateriaSource(MateriaSource const & other);
		virtual ~MateriaSource(void);

		virtual void learnMateria(AMateria * m);
		virtual AMateria* createMateria(std::string const & type);

		MateriaSource &operator=(MateriaSource const & rhs);

	protected:

		AMateria *_knowledge[4];

};

#endif