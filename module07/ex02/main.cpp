#include "Array.hpp"
#include <iostream>

int main(void)
{
	{
		Array<int> arr(10);
		std::cout << "array size: " << arr.size() << std::endl;
		arr[2] = 8;
		std::cout << arr << std::endl;
	}
}