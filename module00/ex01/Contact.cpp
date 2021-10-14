#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::prompt()
{
	std::cout << "Creating a new contact:" << std::endl;
	std::cout << "\nFirst Name:" << std::endl;
	std::getline(std::cin, this->first_name);
	std::cout << "\nLast name:" << std::endl;
	std::getline(std::cin, this->last_name);
	std::cout << "\nNickname:" << std::endl;
	std::getline(std::cin, this->nickname);
	std::cout << "\nPhone number:" << std::endl;
	std::getline(std::cin, this->phone_number);
	std::cout << "\nDarkest secret:" << std::endl;
	std::getline(std::cin, this->darkest_secret);
}

void Contact::print_summary(int index)
{
	std::cout << "|" << std::setw(10) << index << "|";
	if (this->first_name.length() > 10)
		std::cout << this->first_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << this->first_name << "|";
	if (this->last_name.length() > 10)
		std::cout << this->last_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << this->last_name << "|";
	if (this->nickname.length() > 10)
		std::cout << this->nickname.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << this->nickname << "|";
	std::cout << std::endl;
}

void Contact::print_info()
{
	std::cout << "First Name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}
