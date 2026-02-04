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
	while (true){
		Print::printSLn("ADD | SEARCH | EXIT", Color::White());
		if (Validation::validString("Please select an option: ", response)) {return (1);}
		if (response == "ADD"){
			if (Validation::validString("Name: ", firstName)) {return 1;}
			if (Validation::validString("Last Name: ", lastName)) {return 1;}
			if (Validation::validString("Nickname: ", nickName)) {return 1;}
			if (Validation::validNumeric("Phone Number: ", phoneNumber)) {return 1;}
			if (Validation::validString("Darkset Secret: ", darkestSecret)) {return 1;}
			book.add(firstName, lastName, nickName, phoneNumber, darkestSecret);
		}
		else if (response == "SEARCH"){
			if (book.search()) {return 1;};
		}
		else if (response == "EXIT"){
			book.exit();
			break;
		}
		else
			Print::printSLn("invalid input!", Color::Red());
	}
	return 0;
}