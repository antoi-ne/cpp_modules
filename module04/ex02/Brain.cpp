#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::Brain(Brain const & other)
{
	std::cout << "Copy constructor called for Brain" << std::endl;
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << "Destructor called for Brain" << std::endl;
}

Brain &Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
	{
		for(size_t i = 0; i < rhs._ideas->length(); i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}
