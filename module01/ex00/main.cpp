#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie* joseph = newZombie("Joseph Heap");
	joseph->announce();
	delete joseph;

	randomChump("Bob Stack");

	return (0);
}
