#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid usage: only one parameter accepted." << std::endl;
		return (42);
	}

	Karen karen;

	karen.complain(argv[1]);
	return (0);
}