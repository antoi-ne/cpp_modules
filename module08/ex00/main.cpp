#include <easyfind.hpp>
#include <list>
#include <iostream>
#include <stdexcept>

int main(void)
{
	try
	{
		std::list<int> lst;

		lst.push_back(4);

		std::cout << easyfind(lst, 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}