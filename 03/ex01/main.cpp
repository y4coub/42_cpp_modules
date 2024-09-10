/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:26:02 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/10 14:56:12 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // Test ScavTrap
    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav1("Scavvy");

    scav1.attack("Scav2");
    
    scav1.guardGate();
    scav1.guardGate(); // Toggle off

    // Test inheritance
    ClapTrap* polyScav = new ScavTrap("PolyScav");
    polyScav->attack("Target");
    delete polyScav;

    return 0;
}