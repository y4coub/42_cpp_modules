/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:43:56 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/06 18:12:29 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int parse_level(std::string level)
{
	if (level == "DEBUG")
		return (DEBUG);
	else if (level == "INFO")
		return (INFO);
	else if (level == "WARNING")
		return (WARNING);
	else if (level == "ERROR")
		return (ERROR);
	else
		return (-1);
}

int main(int ac, char **av)
{
	Harl harl;
	int level;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter [level]" << std::endl;
		return (1);
	}
	level = parse_level(std::string(av[1]));

	for (int i = 0; i < 4; i++)
	{
		if (level == -1)
		{
			harl.complain(-1);
			return (1);
		}
		if (i < level)
			continue;
		harl.complain(i);
	}
	return (0);
}