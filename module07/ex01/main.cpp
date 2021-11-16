#include "iter.hpp"
#include <iostream>

void display_int(int & i)
{
	std::cout << i << std::endl;
}

void display_string(std::string & s)
{
	std::cout << s << std::endl;
}

void capitalize_string(std::string & s)
{
	s[0] = std::toupper(s[0]);
}

int main(void)
{
	std::cout << "=== Testing on int ===" << std::endl;
	{
		int *array = new int[5];
		array[0] = 4;
		array[1] = 8;
		array[2] = 16;
		array[3] = 32;
		array[4] = 64;
		iter(array, 5, display_int);
	}
	std::cout << "=== Testing on string ===" << std::endl;
	{
		std::string *array = new std::string[3];
		array[0] = "hello";
		array[1] = "world";
		array[2] = "!";
		iter(array, 3, display_string);
		iter(array, 3, capitalize_string);
		iter(array, 3, display_string);
	}
}
