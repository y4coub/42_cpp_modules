/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:47:29 by yaharkat          #+#    #+#             */
/*   Updated: 2024/07/09 15:54:20 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string removeWhiteSpaces(std::string str)
{
	std::string s;
	int start = 0;
	int end = str.length() - 1;

	while (isspace(str[start]))
		start++;

	while (isspace(str[end]))
		end--;

	for (int i = start; i <= end; i++)
		s += str[i];

	return (s);
}

Contact::Contact(void)
{
	_firstName = "    --    ";
	_lastName = "    --    ";
	_nickName = "    --    ";
	_phoneNumber = "    --    ";
	_darkestSecret = "    --    ";
}

Contact::Contact(std::string firstName, std::string lastName,
				 std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	setFirstName(firstName);
	setLastName(lastName);
	setNickName(nickName);
	setPhoneNumber(phoneNumber);
	setDarkestSecret(darkestSecret);
}

void Contact::setFirstName(std::string firstName)
{
	if (firstName.length() > 0)
		_firstName = removeWhiteSpaces(firstName);
	else
		_firstName = "    --    ";
}

void Contact::setLastName(std::string lastName)
{
	if (lastName.length() > 0)
		_lastName = removeWhiteSpaces(lastName);
	else
		_lastName = "    --    ";
}

bool Contact::isEmpty(void)
{
	if ((_firstName == "    --    " || _firstName == "") && (_lastName == "    --    ") && (_nickName == "    --    " || _nickName == "") && (_phoneNumber == "    --    " || _phoneNumber == "") && (_darkestSecret == "    --    " || _darkestSecret == ""))
		return true;
	else
		return false;
}

void Contact::setNickName(std::string nickName)
{
	if (nickName.length() > 0)
		_nickName = removeWhiteSpaces(nickName);
	else
		_nickName = "    --    ";
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	if (phoneNumber.length() > 0)
		_phoneNumber = removeWhiteSpaces(phoneNumber);
	else
		_phoneNumber = "    --    ";
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	if (darkestSecret.length() > 0)
		_darkestSecret = darkestSecret;
	else
		_darkestSecret = "    --    ";
}

std::string Contact::getFirstName()
{
	return (_firstName);
}

std::string Contact::getLastName()
{
	return (_lastName);
}

std::string Contact::getNickName()
{
	return (_nickName);
}

std::string Contact::getPhoneNumber()
{
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret()
{
	return (_darkestSecret);
}