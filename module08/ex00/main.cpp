#include "easyfind.hpp"
#include <list>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <forward_list>
#include <array>

int main(void)
{
	std::cout << "=== arrays ===" << std::endl;
	{
		std::cout << "> element not in array" << std::endl;
		try
		{
			std::array<int, 4> arr;

			arr[0] = 4;
			arr[1] = 8;
			arr[2] = 12;
			arr[3] = 16;

			int f = easyfind(arr, 1);
			std::cout << "found: "<< f << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "> element in array" << std::endl;
		try
		{
			std::array<int, 4> arr;

			arr[0] = 4;
			arr[1] = 8;
			arr[2] = 12;
			arr[3] = 16;

			std::cout << "found: "<< easyfind(arr, 12) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "=== lists ===" << std::endl;
	{
		std::cout << "> element not in list" << std::endl;
		try
		{
			std::list<int> lst;

			lst.push_back(4);
			lst.push_back(8);
			lst.push_back(12);
			lst.push_back(16);

			int f = easyfind(lst, 1);
			std::cout << "found: "<< f << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "> element in list" << std::endl;
		try
		{
			std::list<int> lst;

			lst.push_back(4);
			lst.push_back(8);
			lst.push_back(12);
			lst.push_back(16);

			std::cout << "found: "<< easyfind(lst, 12) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "=== forward_lists ===" << std::endl;
	{
		std::cout << "> element not in forward_list" << std::endl;
		try
		{
			std::forward_list<int> lst;

			lst.push_front(4);
			lst.push_front(8);
			lst.push_front(12);
			lst.push_front(16);

			int f = easyfind(lst, 1);
			std::cout << "found: "<< f << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "> element in forward_list" << std::endl;
		try
		{
			std::forward_list<int> lst;

			lst.push_front(4);
			lst.push_front(8);
			lst.push_front(12);
			lst.push_front(16);

			std::cout << "found: "<< easyfind(lst, 12) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << "=== Vector ===" << std::endl;
	{
		std::cout << "> element not in Vector" << std::endl;
		try
		{
			std::vector<int> vec;

			vec.push_back(4);
			vec.push_back(8);
			vec.push_back(12);
			vec.push_back(16);

			int f = easyfind(vec, 1);
			std::cout << "found: "<< f << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "> element in list" << std::endl;
		try
		{
			std::vector<int> vec;

			vec.push_back(4);
			vec.push_back(8);
			vec.push_back(12);
			vec.push_back(16);

			std::cout << "found: "<< easyfind(vec, 12) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}