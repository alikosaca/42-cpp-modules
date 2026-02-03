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
	Print::printSLn("---------------------------------------------", Color::Orange());
	Print::printS("|", Color::Orange());
	Print::printS("  Index|  First Name|  Last Name|  Nickname", Color::Blue());
	Print::printSLn("|", Color::Orange());
	Print::printSLn("---------------------------------------------", Color::Orange());
    for (int i = 0; i < id; i++)
    {
        Print::printS("|", Color::Orange());
		std::cout << std::setw(7) << i;
		std::cout << Color::Blue() << std::setw(0) << "|" << Color::ResetColor();
		std::cout << std::setw(12) << Print::shorten(_contact[i].getFirstName());
		Print::printS("|", Color::Blue());
        std::cout << std::setw(11) << Print::shorten(_contact[i].getLastName());
		Print::printS("|", Color::Blue());
        std::cout << std::setw(10) << Print::shorten(_contact[i].getNickName());
		Print::printSLn("|", Color::Orange());
	}			
	Print::printSLn("---------------------------------------------", Color::Orange());
	while (true)
	{
		std::string value;
		Validation::validNumeric(": ", value);
		int inputIndex = std::atoi(value.c_str());
		
		if (inputIndex > (id-1))
			Print::printSLn("Invalid index! Please enter the existing index number in the list!", Color::Red());
		else
		{
			Print::printS("First Name    : ", Color::Blue());
			Print::printSLn(_contact[inputIndex].getFirstName(), Color::Green());

			print::printS("Last Name     : ", Color::Blue());
			print::printSLn(_contact[inputIndex].getLastName(), Color::Green());

			Print::printS("Nickname      : ", Color::Blue());
			Print::printSLn(_contact[inputIndex].getNickName(), Color::Green());

			Print::printS("Phone Number  : ", Color::Blue());
			Print::printSLn(_contact[inputIndex].getPhoneNumber(), Color::Green());

			Print::printS("Darkest Secret: ", Color::Blue());
			Print::printSLn(_contact[inputIndex].getDarkestSecret(), Color::Green());
			break;
		}
	}
}
