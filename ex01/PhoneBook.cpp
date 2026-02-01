#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0){}
PhoneBook::~PhoneBook(){}

void PhoneBook::add(std::string name, std::string phoneNumber)
{
	if (name.empty() || phoneNumber.empty())
		return;
	int id = this->index % 8;
	this->_contact[id].setContact(name, phoneNumber);
	index++;
}

void PhoneBook::display()
{
	for(int i = 0; i < 8; i++)
	{
		if (this->_contact[i].displayContact() == )
		std::cout << "Index: " << i << " : ";
		this->_contact[i].displayContact();
	}
}