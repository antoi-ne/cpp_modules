#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap steve("Steve");
	steve.attack("Joe");
	steve.takeDamage(9);
	steve.takeDamage(2);
	steve.beRepaired(6);
	steve.beRepaired(1);

	ClapTrap steve2;
	steve2 = steve;
	steve2.attack("Joe2");
	steve2.takeDamage(1);

	ClapTrap steve3(steve2);
	steve2.attack("Joe3");
	steve3.takeDamage(3);
	return 0;
}