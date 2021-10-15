#include "Karen.hpp"

Karen::Karen()
{
}

Karen::~Karen()
{
}

void Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level)
{
	std::string level_keys[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};	
	int level_id = 0;

	for (size_t i = 0; i < 4; i++)
	{
		if (level_keys[i]== level)
		{
			level_id = i + 1;
			break;
		}
	}

	switch (level_id)
	{
	case 1:
		std::cout << "[ DEBUG ]" << std::endl;
		this->debug();
		std::cout << std::endl;
	case 2:
		std::cout << "[ INFO ]" << std::endl;
		this->info();
		std::cout << std::endl;
	case 3:
		std::cout << "[ WARNING ]" << std::endl;
		this->warning();
		std::cout << std::endl;
	case 4:
		std::cout << "[ ERROR ]" << std::endl;
		this->error();
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
