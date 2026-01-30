#include "Contact.hpp"
#include <string>
#include <iostream>

Contact::Contact(){}
Contact::~Contact(){}

void Contact::SetContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret){
	_firstName = firstName;
	_lastName = lastName;
	_nickName = nickName;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

std::string Contact::GetFirstName() const{
	return(_firstName);
}

std::string Contact::GetLastName() const{
	return(_lastName);
}

std::string Contact::GetNickName() const{
	return(_nickName);
}

std::string Contact::GetPhoneNumber() const{
	return(_phoneNumber);
}

std::string Contact::GetDarkestSecret() const{
	return (_darkestSecret);
}
