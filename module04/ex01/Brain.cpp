#include "Brain.hpp"

Brain::Brain(void)
{}

Brain::Brain(Brain const & other)
{
	*this = other;
}

Brain::~Brain(void)
{}

Brain &Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
	{
		for(size_t i = 0; i < rhs._ideas->length(); i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}
