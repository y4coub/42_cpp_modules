/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:43:56 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/06 17:27:11 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "DEBUG: ";
	harl.complain(DEBUG);
	std::cout << "INFO: ";
	harl.complain(INFO);
	std::cout << "WARNING: ";
	harl.complain(WARNING);
	std::cout << "ERROR: ";
	harl.complain(ERROR);
	return (0);
}