#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

std::string Contact::getFirstName() const{
    return this->_firstName;
}

std::string Contact::getLastName() const{
    return this->_lastName;
}

std::string Contact::getNickName() const{
    return this->_nickName;
}

std::string Contact::getPhoneNumber() const{
    return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const{
    return this->_darkestSecret;
}

void Contact::setFirstName(const std::string& firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickName(const std::string& nickName)
{
	this->_nickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

void Contact::setAll(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber, const std::string& darkestSecret){
	setFirstName(firstName);
	setLastName(lastName);
	setNickName(nickName);
	setPhoneNumber(phoneNumber);
	setDarkestSecret(darkestSecret);
}

