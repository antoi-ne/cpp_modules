#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include "Contact.hpp"

class Phonebook
{
	private:
		Contact _contacts[8];
		size_t _contacts_count;

		void _add_contact(Contact contact);
		void _print_summary();

	public:
		Phonebook();
		~Phonebook();
		int prompt();
};

#endif