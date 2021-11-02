#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "=== subject example ===" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << "=== extended tests ===" << std::endl;
	{
		ICharacter *c1 = new Character("c1");
		ICharacter *c2 = new Character("c2");

		IMateriaSource *src1 = new MateriaSource();
		IMateriaSource *src2 = new MateriaSource();

		src1->learnMateria(new Ice());
		src2->learnMateria(new Cure());

		c1->equip(src1->createMateria("ice"));
		c1->equip(src2->createMateria("ice"));
		c2->equip(src1->createMateria("cure"));
		c2->equip(src2->createMateria("cure"));

		c1->use(0, *c2);
		c1->use(1, *c2);
		c2->use(0, *c1);
		c2->use(1, *c1);

		delete c1;
		delete c2;
		delete src1;
		delete src2;
	}
}