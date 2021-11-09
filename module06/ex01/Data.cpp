#include "Data.hpp"

Data::Data(void)
{
}

Data::Data(Data const & other)
{
	*this = other;
}

Data::~Data(void)
{
}

Data &Data::operator=(Data const & rhs)
{
	(void)rhs;
	return *this;
}