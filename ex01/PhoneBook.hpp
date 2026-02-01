#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private:
	Contact _contact[8];
	int index;

	public:
	PhoneBook();
	~PhoneBook();

	void add(std::string name, std::string phoneNumber);
	void display();
};

#endif