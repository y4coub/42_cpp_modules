/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:30:03 by yaharkat          #+#    #+#             */
/*   Updated: 2024/07/09 15:31:45 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <limits>

class PhoneBook
{
	Contact contacts[8];
	int contactIndex = 0;
	bool replacedOldContact;

  private:
	void displayContacts(void);
	void displayOneContact(int i);

  public:
	PhoneBook(void);
	PhoneBook(Contact contacts[8], int contactIndex);
	void addContact(void);
	void searchContact(void);
	int length(void);
};

#endif