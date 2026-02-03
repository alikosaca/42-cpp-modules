#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Validation.hpp"


int main(void)
{
	PhoneBook book;
	std::string tempName;
	std::string tempPhone;
	std::string response;

	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
	bool run = true;

	Print::printSLn("<<<--- Welcome! --->>>", Color::Green());
	while (run)
	{
		Print::printSLn("ADD | SEARCH | EXIT", Color::White());
		Print::printS("Please select an option: ", Color::Blue());
		std::getline(std::cin >> std::ws, response);
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
			Print::printSLn("Have a nice day. Exit enabled", Color::Green());
			break;
		}
	}
	return 0;
}