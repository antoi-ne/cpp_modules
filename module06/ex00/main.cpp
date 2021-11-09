#include "ScalarConvertor.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments." << std::endl;
		return 1;
	}
	try
	{
		ScalarConvertor sc(argv[1]);

		double base = sc.toDouble();

		std::cout << "char: ";
		if (base >=0 && base <= 255 && !std::isnan(base))
		{
			if (std::isprint(sc.toChar()))
				std::cout << sc.toChar();
			else
				std::cout << "Non displayable";
		}
		else
			std::cout << "impossible";
		std::cout << std::endl;

		std::cout << "int: ";
		if (base >=INT_MIN && base <= INT_MAX && !std::isnan(base))
			std::cout << sc.toInt();
		else
			std::cout << "impossible";
		std::cout << std::endl;

		if (floor(base) == base)
		{
			std::cout << "float: " << std::setprecision(1) << std::fixed << sc.toFloat() << "f" << std::endl;

			std::cout << "double: " << std::setprecision(1) << std::fixed << sc.toDouble() << std::endl;
		}
		else
		{
			std::cout << "float: " << std::fixed << sc.toFloat() << "f" << std::endl;

			std::cout << "double: " << std::fixed << sc.toDouble() << std::endl;
		}
		

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
