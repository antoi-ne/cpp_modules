#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{

	public:

		Cat(void);
		Cat(Cat const & other);
		virtual ~Cat(void);

		virtual void makeSound(void) const;

		Cat &operator=(Cat const & rhs);

	private:

		Brain * _brain;

};

#endif