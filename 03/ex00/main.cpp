/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:26:02 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/09 19:06:33 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	// Create ClapTraps
	ClapTrap clap1("CT-1");
	ClapTrap clap2("CT-2");
	ClapTrap clap3("CT-3");

	// Test attacks
	std::cout << "\nTesting attacks:" << std::endl;
	clap1.attack(clap2);
	clap2.attack(clap3);
	clap3.attack(clap1);

	// Test repairs
	std::cout << "\nTesting repairs:" << std::endl;
	clap1.beRepaired(3);
	clap2.beRepaired(5); // Should fail because CT-2 is dead
	clap3.beRepaired(2);

	// Test energy depletion
	std::cout << "\nTesting energy depletion:" << std::endl;
	for (int i = 0; i < 11; ++i)
	{
		clap3.attack(clap1); // Should run out of energy on the 10th attack
	}

	// Test attacking a dead ClapTrap
	std::cout << "\nTesting attack on dead ClapTrap:" << std::endl;
	clap1.attack(clap2); // CT-2 is dead, but the attack should still occur

	return 0;
}