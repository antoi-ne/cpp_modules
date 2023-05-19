#include <iostream>
#include "Array.hpp"

#define MAX_VAL 12
int main(int, char **)
{
	Array<int> empty;
	std::cout << "Empty array: " << empty << std::endl;

	Array<int> a(10);
	std::cout << "Default init. array: " << a << std::endl;

	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

		std::cout << "size: " << numbers.size() << " - should be " << MAX_VAL << std::endl;

	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);

		std::cout << "array: " << numbers << std::endl;
		std::cout << "copy: " << test << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "array copied sucessfully" << std::endl;
	std::cout << "trying to access negative index" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "trying to access index >= len" << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	delete[] mirror;
	return 0;
}