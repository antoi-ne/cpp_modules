#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap steve("Steve");
	ClapTrap steve2;

	steve.attack("Joe");
	steve.takeDamage(9);
	steve.takeDamage(2);
	steve.beRepaired(6);
	steve.beRepaired(1);

	steve2 = steve;
	steve.attack("Joe");
	return 0;
}