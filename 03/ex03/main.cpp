/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:34:08 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/30 16:45:36 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== Starting DiamondTrap Test Program =====" << std::endl;

	// Creating two DiamondTrap objects with different names
	DiamondTrap Diamo("Diamo");
	DiamondTrap bobby("Bobby");

	std::cout << "\n--- Initial State of Diamo and Bobby ---" << std::endl;
	Diamo.attack("Bobby");					   // Diamo attacks Bobby (default attack damage is 0)
	bobby.takeDamage(Diamo.getAttackDamage()); // Bobby takes 20 damage (just testing interaction)

	// Changing Diamo's attack damage and attacking Bobby
	std::cout << "\n--- Diamo Attacks with Modified Damage ---" << std::endl;
	Diamo.takeDamage(10);					   // Diamo takes 3 points of damage to reduce his hit points.
	Diamo.attack("Bobby");					   // Diamo attacks Bobby (damage is still 0 by default)
	bobby.takeDamage(Diamo.getAttackDamage()); // Bobby takes the attack

	// Manually change Diamo's attack damage for testing
	std::cout << "\n--- Modify Diamo's Attack Damage ---" << std::endl;
	Diamo.setAttackDamage(5);				   // Pretend like we've upgraded Diamo's attack
	Diamo.attack("Bobby");					   // Diamo now attacks Bobby with 5 attack damage
	bobby.takeDamage(Diamo.getAttackDamage()); // Bobby should lose 5 hit points

	// Diamo attempts to repair himself
	std::cout << "\n--- Diamo Repairs ---" << std::endl;
	Diamo.beRepaired(5); // Diamo repairs and gains 5 hit points back.

	// Bobby takes more damage
	std::cout << "\n--- Bobby Takes More Damage ---" << std::endl;
	bobby.takeDamage(7); // Bobby loses 7 hit points
	bobby.beRepaired(2); // Bobby repairs 2 hit points

	// Run out of energy for Diamo
	std::cout << "\n--- Diamo Runs Out of Energy ---" << std::endl;
	for (int i = 0; i < 101; ++i) // Diamo attacks until his energy is depleted
	{
		Diamo.attack("Bobby");
	}

	// Test for insufficient energy/hit points
	std::cout << "\n--- Diamo Attempts to Attack and Repair with No Energy ---" << std::endl;
	Diamo.attack("Bobby");
	Diamo.beRepaired(3);

	// Copy constructor test
	std::cout << "\n--- Creating a Copy of Diamo (DiamoCopy) ---" << std::endl;
	DiamondTrap DiamoCopy(Diamo);
	DiamoCopy.attack("Bobby"); // Test if copy behaves like Diamo

	// Assignment operator test
	std::cout << "\n--- Assigning Bobby's State to DiamoCopy ---" << std::endl;
	DiamoCopy = bobby;		   // Using the overloaded assignment operator
	DiamoCopy.attack("Diamo"); // Testing if DiamoCopy behaves like Bobby now


	// DiamondTrap WhoAmI
	std::cout << "\n--- WhoAmI Testing ---" << std::endl;
	DiamoCopy.whoAmI();
	
	std::cout << "\n===== End of DiamondTrap Test Program =====" << std::endl;

	return 0;
}
