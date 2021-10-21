#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{

	public:

		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const & other);
		virtual ~WrongAnimal(void);

		std::string getType(void) const;

		void makeSound(void) const;

		WrongAnimal &operator=(WrongAnimal const & rhs);

	protected:

		std::string _type;

};

#endif