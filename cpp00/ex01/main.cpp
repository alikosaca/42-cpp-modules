#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Validation.hpp"


int main(void)
{
	PhoneBook book;
	std::string response;
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	Print::printSLn("<<<--- Welcome! --->>>", Color::Green());
	while (true)
	{
		Print::printSLn("ADD | SEARCH | EXIT", Color::White());
		Validation::validString("Please select an option: ", response);
		if (response == "ADD")
		{
			Validation::validString("Name: ", firstName);
			Validation::validString("Last Name: ", lastName);
			Validation::validString("Nickname: ", nickName);
			Validation::validNumeric("Phone Number: ", phoneNumber);
			Validation::validString("Darkset Secret: ", darkestSecret);
			book.add(firstName, lastName, nickName, phoneNumber, darkestSecret);
		}
		else if (response == "SEARCH")
		{
			book.search();
		}
		else if (response == "EXIT")
		{
			book.exit();
			break;
		}
		else
			Print::printSLn("invalid input!", Color::Red());
	}
	return 0;
}