#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{

	public:

		WrongCat(void);
		WrongCat(WrongCat const & other);
		virtual ~WrongCat(void);

		virtual void makeSound(void) const;

		WrongCat &operator=(WrongCat const & rhs);

	private:

};

#endif