#include "PhoneBook.hpp"
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : index(0){}
PhoneBook::~PhoneBook(){}

void PhoneBook::add(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber, const std::string& darkestSecret)
{
	if (firstName.empty() || lastName.empty() || nickName.empty() || phoneNumber.empty() || darkestSecret.empty())
	{
		std::cout << "\e[31m" << " Kullanıcı eklenemedi." << std::endl;
		return ;
	}
	int id = this->index % 8;
	this->_contact[id].setAll(firstName, lastName, nickName, phoneNumber, darkestSecret);
	index++;
	std::cout << "\e[32m" <<  firstName << " Başarıyla eklendi." << std::endl;
}

static std::string formatField(const std::string& s)
{
    if (s.size() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

void PhoneBook::search()
{
	int id = (this->index < 8) ? this->index : 8;
	if (id == 0)
	{
		std::cout << "Rehber boş."  << std::endl;
		return;
	}
	std::cout << "Index | First Name | Last Name | Nickname" << std::endl;
    for (int i = 0; i < id; ++i)
    {
        std::cout << std::setw(5) << i << " | "
                  << std::setw(10) << formatField(this->_contact[i].getFirstName()) << " | "
                  << std::setw(10) << formatField(this->_contact[i].getLastName()) << " | "
                  << std::setw(10) << formatField(this->_contact[i].getNickName()) << std::endl;
    }

}