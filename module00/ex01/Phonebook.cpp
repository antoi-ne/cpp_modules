#include <iostream>
#include <string>
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
	for (size_t i = 0; i < this->_contacts_count; i++)
		this->_contacts[i].print_summary(i);
	std::cout << "|===========================================|" << std::endl;
}

int Phonebook::prompt()
{
	std::string input;

	std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
	std::getline(std::cin, input);
	if (input == "ADD")
	{
		Contact contact;
		contact.prompt();
		this->_add_contact(contact);
	}
	else if (input == "SEARCH")
	{
		this->_print_summary();
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
