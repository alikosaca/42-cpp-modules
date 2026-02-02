#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "print.hpp"
#include "color.hpp"

class PhoneBook{
	private:
	Contact _contact[8];
	int index;

	public:
	PhoneBook();
	~PhoneBook();

	void add(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber, const std::string& darkestSecret);
	void search();
};

#endif