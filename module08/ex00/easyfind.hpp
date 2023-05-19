#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>

class OccurenceNotFoundException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Occurence not found in container.";
				}
		};

template <typename T>
int & easyfind(T & a, int b)
{
	typename T::iterator it;
	it = std::find(a.begin(), a.end(), b);
	if (it == a.end())
		throw OccurenceNotFoundException();
	return *it;
}

#endif
