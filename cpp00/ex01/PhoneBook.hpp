#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cstdlib>
#include "Contact.hpp"
#include "Print.hpp"
#include "Color.hpp"
#include "Validation.hpp"

class PhoneBook
{
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