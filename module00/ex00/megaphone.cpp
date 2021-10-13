#include <iostream>

int main(int ac, char *av[])
{
	(void)av;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			char *str = av[i];
			for (size_t j = 0; j < strlen(str); j++)
			{
				str[j] = toupper(str[j]);
			}
			std::cout << str;
		}
		std::cout << std::endl;
	}
}