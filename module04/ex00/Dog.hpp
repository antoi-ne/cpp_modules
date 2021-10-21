#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog: public Animal
{

	public:

		Dog(void);
		Dog(Dog const & other);
		~Dog(void);

		virtual void makeSound(void) const;

		Dog &operator=(Dog const & rhs);

};

#endif
