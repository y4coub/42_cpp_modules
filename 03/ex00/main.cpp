/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:34:08 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/30 16:09:08 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== Starting ClapTrap Test Program =====" << std::endl;

	// Creating two ClapTrap objects with different names
	ClapTrap clappy("Clappy");
	ClapTrap bobby("Bobby");

	std::cout << "\n--- Initial State of Clappy and Bobby ---" << std::endl;
	clappy.attack("Bobby"); // Clappy attacks Bobby (default attack damage is 0)
	bobby.takeDamage(0);	// Bobby takes 0 damage (just testing interaction)

	// Changing Clappy's attack damage and attacking Bobby
	std::cout << "\n--- Clappy Attacks with Modified Damage ---" << std::endl;
	clappy.takeDamage(3);						// Clappy takes 3 points of damage to reduce his hit points.
	clappy.attack("Bobby");						// Clappy attacks Bobby (damage is still 0 by default)
	bobby.takeDamage(clappy.getAttackDamage()); // Bobby takes the attack

	// Manually change Clappy's attack damage for testing
	std::cout << "\n--- Modify Clappy's Attack Damage ---" << std::endl;
	clappy.setAttackDamage(5);				 // Pretend like we've upgraded Clappy's attack
	clappy.attack("Bobby");					 // Clappy now attacks Bobby with 5 attack damage
	bobby.takeDamage(clappy.getAttackDamage()); // Bobby should lose 5 hit points

	// Clappy attempts to repair himself
	std::cout << "\n--- Clappy Repairs ---" << std::endl;
	clappy.beRepaired(5); // Clappy repairs and gains 5 hit points back.

	// Bobby takes more damage
	std::cout << "\n--- Bobby Takes More Damage ---" << std::endl;
	bobby.takeDamage(7); // Bobby loses 7 hit points
	bobby.beRepaired(2); // Bobby repairs 2 hit points

	// Run out of energy for Clappy
	std::cout << "\n--- Clappy Runs Out of Energy ---" << std::endl;
	for (int i = 0; i < 11; ++i) // Clappy attacks until his energy is depleted
	{
		clappy.attack("Bobby");
	}

	// Test for insufficient energy/hit points
	std::cout << "\n--- Clappy Attempts to Attack and Repair with No Energy ---" << std::endl;
	clappy.attack("Bobby");
	clappy.beRepaired(3);

	// Copy constructor test
	std::cout << "\n--- Creating a Copy of Clappy (ClappyCopy) ---" << std::endl;
	ClapTrap clappyCopy(clappy);
	clappyCopy.attack("Bobby"); // Test if copy behaves like Clappy

	// Assignment operator test
	std::cout << "\n--- Assigning Bobby's State to ClappyCopy ---" << std::endl;
	clappyCopy = bobby;			 // Using the overloaded assignment operator
	clappyCopy.attack("Clappy"); // Testing if ClappyCopy behaves like Bobby now

	std::cout << "\n===== End of ClapTrap Test Program =====" << std::endl;

	return 0;
}
