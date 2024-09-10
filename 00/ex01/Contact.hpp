/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:54:38 by yaharkat          #+#    #+#             */
/*   Updated: 2024/07/07 12:22:44 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__
# include <iostream>
class Contact
{
  private:
	std::string _firstName = "    --    ";
	std::string _lastName = "    --    ";
	std::string _nickName = "    --    ";
	std::string _phoneNumber = "    --    ";
	std::string _darkestSecret = "    --    ";

  public:
	Contact(std::string firstName, std::string lastName, std::string nickName,
		std::string phoneNumber, std::string darkestSecret);
	void setFirstName(std::string _firstName);
	void setLastName(std::string _lastName);
	bool isEmpty(void);
	void setNickName(std::string _nickName);
	void setPhoneNumber(std::string _phoneNumber);
	void setDarkestSecret(std::string _darkestSecret);
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
	Contact(void);
};

std::string removeWhiteSpaces(std::string str);

#endif