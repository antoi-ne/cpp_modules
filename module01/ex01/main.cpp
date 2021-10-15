#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	int hordeSize = 2;
	std::string hordeName("Rick");

	Zombie *horde = zombieHorde(hordeSize, hordeName);

	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();

	delete [] horde;

	return (0);
}
