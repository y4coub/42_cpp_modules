/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:34:08 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/30 16:18:46 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "===== Starting FragTrap Test Program =====" << std::endl;

	// Creating two FragTrap objects with different names
	FragTrap Fraggy("Fraggy");
	FragTrap bobby("Bobby");

	std::cout << "\n--- Initial State of Fraggy and Bobby ---" << std::endl;
	Fraggy.attack("Bobby");					   // Fraggy attacks Bobby (default attack damage is 0)
	bobby.takeDamage(Fraggy.getAttackDamage()); // Bobby takes 20 damage (just testing interaction)

	// Changing Fraggy's attack damage and attacking Bobby
	std::cout << "\n--- Fraggy Attacks with Modified Damage ---" << std::endl;
	Fraggy.takeDamage(10);					   // Fraggy takes 3 points of damage to reduce his hit points.
	Fraggy.attack("Bobby");					   // Fraggy attacks Bobby (damage is still 0 by default)
	bobby.takeDamage(Fraggy.getAttackDamage()); // Bobby takes the attack

	// Manually change Fraggy's attack damage for testing
	std::cout << "\n--- Modify Fraggy's Attack Damage ---" << std::endl;
	Fraggy.setAttackDamage(5);				   // Pretend like we've upgraded Fraggy's attack
	Fraggy.attack("Bobby");					   // Fraggy now attacks Bobby with 5 attack damage
	bobby.takeDamage(Fraggy.getAttackDamage()); // Bobby should lose 5 hit points

	// Fraggy attempts to repair himself
	std::cout << "\n--- Fraggy Repairs ---" << std::endl;
	Fraggy.beRepaired(5); // Fraggy repairs and gains 5 hit points back.

	// Bobby takes more damage
	std::cout << "\n--- Bobby Takes More Damage ---" << std::endl;
	bobby.takeDamage(7); // Bobby loses 7 hit points
	bobby.beRepaired(2); // Bobby repairs 2 hit points

	// Run out of energy for Fraggy
	std::cout << "\n--- Fraggy Runs Out of Energy ---" << std::endl;
	for (int i = 0; i < 101; ++i) // Fraggy attacks until his energy is depleted
	{
		Fraggy.attack("Bobby");
	}

	// Test for insufficient energy/hit points
	std::cout << "\n--- Fraggy Attempts to Attack and Repair with No Energy ---" << std::endl;
	Fraggy.attack("Bobby");
	Fraggy.beRepaired(3);

	// Copy constructor test
	std::cout << "\n--- Creating a Copy of Fraggy (FraggyCopy) ---" << std::endl;
	FragTrap FraggyCopy(Fraggy);
	FraggyCopy.attack("Bobby"); // Test if copy behaves like Fraggy

	// Assignment operator test
	std::cout << "\n--- Assigning Bobby's State to FraggyCopy ---" << std::endl;
	FraggyCopy = bobby;		   // Using the overloaded assignment operator
	FraggyCopy.attack("Fraggy"); // Testing if FraggyCopy behaves like Bobby now


	// FragTrap HighFive
	std::cout << "\n--- High Five Testing ---" << std::endl;
	FraggyCopy.highFivesGuys();
	
	std::cout << "\n===== End of FragTrap Test Program =====" << std::endl;

	return 0;
}
