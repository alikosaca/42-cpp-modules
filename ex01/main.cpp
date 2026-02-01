#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook book;
	std::string tempName;
	std::string tempPhone;

	std::cout << "<<<--- Hoş Geldiniz! --->>>" << std::endl;
	// while ()
	// {
	// 	/* code */
	// }
	
	std::cout << "isminizi giriniz: ";
	std::getline(std::cin >> std::ws, tempName);

	std::cout << "Numaranızı giriniz: ";
	std::getline(std::cin >> std::ws, tempPhone);
	book.add(tempName, tempPhone);

	book.display();
}