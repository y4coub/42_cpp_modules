/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:41:40 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/01 16:06:53 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string name = "HI THIS IS BRAIN";

	std::string *stringPTR = &name;
	std::string &stringREF = name;
	

	std::cout << "Address in memory of the string: " << &name << std::endl;
	std::cout << "Address in memory of the stringPTR: " << stringPTR << std::endl;
	std::cout << "Address in memory of the stringREF: " << &stringREF << std::endl;

	std::cout << "Value of the string: " << name << std::endl;
	std::cout << "Value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of the stringREF: " << stringREF << std::endl;
}