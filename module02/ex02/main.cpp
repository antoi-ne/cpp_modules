#include "Fixed.hpp"

int main(void)
{
	std::cout << "== Testing from subject ==" << std::endl;

	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
	}

		std::cout << "== Additional testing ==" << std::endl;

	{
		Fixed a;
		Fixed const b(Fixed(4.44f) + Fixed(2));

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << b - Fixed(1) << std::endl;
		std::cout << b / Fixed(2) << std::endl;
		std::cout << Fixed::max(a + Fixed(10.02f), b/ Fixed(2)) << std::endl;
	}

	return 0;
}