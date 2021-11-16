#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> arr(3);
	std::cout << "array size: " << arr.size() << std::endl;
	arr[0] = 2;
	arr[1] = 4;
	arr[2] = 8;
	std::cout << arr << std::endl;
}
