#include "testing.hpp"

testing::testing()
{
}

testing::~testing()
{
}

testing::testing(const testing &other)
{
	*this = other;
}

testing& testing::operator=(const testing & other) 
{
	if (this != &other)
	{
		this->a = other.a;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, testing const &other)
{
	os << "" << std::endl;
	return (os);
}