#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name): _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << "Destroying zombie: " << this->_name << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
