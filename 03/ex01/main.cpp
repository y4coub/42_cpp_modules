/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:34:08 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/30 16:08:59 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== Starting ScavTrap Test Program =====" << std::endl;

	// Creating two ScavTrap objects with different names
	ScavTrap Scavy("Scavy");
	ScavTrap bobby("Bobby");

	std::cout << "\n--- Initial State of Scavy and Bobby ---" << std::endl;
	Scavy.attack("Bobby");					   // Scavy attacks Bobby (default attack damage is 0)
	bobby.takeDamage(Scavy.getAttackDamage()); // Bobby takes 20 damage (just testing interaction)

	// Changing Scavy's attack damage and attacking Bobby
	std::cout << "\n--- Scavy Attacks with Modified Damage ---" << std::endl;
	Scavy.takeDamage(10);					   // Scavy takes 3 points of damage to reduce his hit points.
	Scavy.attack("Bobby");					   // Scavy attacks Bobby (damage is still 0 by default)
	bobby.takeDamage(Scavy.getAttackDamage()); // Bobby takes the attack

	// Manually change Scavy's attack damage for testing
	std::cout << "\n--- Modify Scavy's Attack Damage ---" << std::endl;
	Scavy.setAttackDamage(5);				   // Pretend like we've upgraded Scavy's attack
	Scavy.attack("Bobby");					   // Scavy now attacks Bobby with 5 attack damage
	bobby.takeDamage(Scavy.getAttackDamage()); // Bobby should lose 5 hit points

	// Scavy attempts to repair himself
	std::cout << "\n--- Scavy Repairs ---" << std::endl;
	Scavy.beRepaired(5); // Scavy repairs and gains 5 hit points back.

	// Bobby takes more damage
	std::cout << "\n--- Bobby Takes More Damage ---" << std::endl;
	bobby.takeDamage(7); // Bobby loses 7 hit points
	bobby.beRepaired(2); // Bobby repairs 2 hit points

	// Run out of energy for Scavy
	std::cout << "\n--- Scavy Runs Out of Energy ---" << std::endl;
	for (int i = 0; i < 51; ++i) // Scavy attacks until his energy is depleted
		Scavy.attack("Bobby");

	// Test for insufficient energy/hit points
	std::cout << "\n--- Scavy Attempts to Attack and Repair with No Energy ---" << std::endl;
	Scavy.attack("Bobby");
	Scavy.beRepaired(3);

	// Copy constructor test
	std::cout << "\n--- Creating a Copy of Scavy (ScavyCopy) ---" << std::endl;
	ScavTrap ScavyCopy(Scavy);
	ScavyCopy.attack("Bobby"); // Test if copy behaves like Scavy

	// Assignment operator test
	std::cout << "\n--- Assigning Bobby's State to ScavyCopy ---" << std::endl;
	ScavyCopy = bobby;		   // Using the overloaded assignment operator
	ScavyCopy.attack("Scavy"); // Testing if ScavyCopy behaves like Bobby now

	// Testing Gate Mode
	std::cout << "\n--- Testing ScavyCopy Gate Mode ---" << std::endl;
	ScavyCopy.guardGate(); // Toogle ON
	ScavyCopy.guardGate(); // Toogle OFF

	std::cout << "\n===== End of ScavTrap Test Program =====" << std::endl;

	return 0;
}
