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

void PhoneBook::search()
{
	int id = (this->index < 8) ? this->index : 8;
	if (id == 0)
	{
		std::cout << "Rehber boş."  << std::endl;
		return;
	}
	print::printSLn("---------------------------------------------", color::orange);
	print::printS("|", color::orange);
	print::printS("  Index|  First Name|  Last Name|  Nickname", color::blue);
	print::printSLn("|", color::orange);
	print::printSLn("---------------------------------------------", color::orange);
    for (int i = 0; i < id; ++i)
    {
		//std::cout << std::setw(6) << color::black <<☺ i << color::resetColor;
        print::printS("|", color::orange);
		std::cout << std::setw(7) << i;
		std::cout << color::blue << std::setw(0) << "|" << color::resetColor;
		std::cout << std::setw(12) << print::shorten(_contact[i].getFirstName());
		print::printS("|", color::blue);
        std::cout << std::setw(11) << print::shorten(_contact[i].getLastName());
		print::printS("|", color::blue);
        std::cout << std::setw(10) << print::shorten(_contact[i].getNickName());
		print::printSLn("|", color::orange);
	}			
	print::printSLn("---------------------------------------------", color::orange);
}