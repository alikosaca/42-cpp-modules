#include "PhoneBook.hpp"
#include "Contact.hpp"

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

	std::cout << "<<<--- Hoş Geldiniz! --->>>" << std::endl;
	while (run)
	{
		std::cout << "\e[0m" << "Lütfen bir seçeneği seçiniz: " << std::endl;
		std::cout << "" << "ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin >> std::ws, response);
		if (response == "ADD")
		{
			std::cout << "\e[36m" << "isim: ";
			std::getline(std::cin >> std::ws, firstName);

			std::cout << "soyisim: ";
			std::getline(std::cin >> std::ws, lastName);

			std::cout << "nick name: ";
			std::getline(std::cin >> std::ws, nickName);
			
			std::cout << "phone number: ";
			std::getline(std::cin >> std::ws, phoneNumber);

			std::cout << "darkestSecret: ";
			std::getline(std::cin >> std::ws, darkestSecret);

			book.add(firstName, lastName, nickName, phoneNumber, darkestSecret);
	
		}
		else if (response == "SEARCH")
		{
			book.search();
		}
		else if (response == "EXIT")
		{
			std::cout << "Program kapandı." << std::endl;
			break;
		}
	}
	
	return 0;
}