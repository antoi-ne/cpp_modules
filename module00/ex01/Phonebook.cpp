#include <iostream>
#include <string>
#include <stdlib.h>
#include <errno.h>
#include "Phonebook.hpp"



Phonebook::Phonebook()
{
	this->_contacts_count = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::_add_contact(Contact contact)
{
	this->_contacts[this->_contacts_count % 8] = contact;
	this->_contacts_count++;
}

void Phonebook::_print_summary()
{
	std::cout << "|===========================================|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (size_t i = 0; i < this->_contacts_count && i < 8; i++)
		this->_contacts[i].print_summary(i);
	std::cout << "|===========================================|" << std::endl;
}

int Phonebook::prompt()
{
	std::string input;

	std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "\nExiting\n";
		return (1);
	}
	if (input == "ADD")
	{
		Contact contact;
		contact.prompt();
		this->_add_contact(contact);
	}
	else if (input == "SEARCH")
	{
		if (this->_contacts_count == 0)
		{
			std::cout << "No contacts yet." << std::endl;
			return (0);
		}
		this->_print_summary();
		std::cout << "Select index: ";
		std::getline(std::cin, input);
		char *endptr;
		errno = 0;
		long res = strtol(input.c_str(), &endptr, 10);
		if (errno != 0 || res > 7 || res < 0 || input[0] == '\0' || endptr[0] != '\0')
		{
			std::cout << "Invalid input, must be digit between 0 and 7." << std::endl;
			return (0);
		}
		if ((size_t)res >= this->_contacts_count)
		{
			std::cout << "This contact index is not defined yet." << std::endl;
			return (0);
		}
		this->_contacts[res].print_info();
		return (0);
	}
	else if (input == "EXIT")
	{
		std::cout << "Exiting." << std::endl;
		return (1);
	}
	else
	{
		std::cout << "Error: unrecognized command." << std::endl;
	}
	return (0);
}
