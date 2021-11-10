#include "iter.hpp"
#include <iostream>

void display(int & i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	int *array = new int[5];
	array[0] = 4;
	array[1] = 8;
	array[2] = 16;
	array[3] = 32;
	array[4] = 64;
	iter(array, 5, display);
	return 0;
}