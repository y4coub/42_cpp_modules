/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:26:02 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/10 14:55:53 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    // Test FragTrap
    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    FragTrap frag1("Fraggy");

    frag1.attack("Trappy");
    frag1.highFivesGuys();

    // Test inheritance
    ClapTrap* polyScav = new FragTrap("PolyScav");
    polyScav->attack("Target");
    delete polyScav;

    return 0;
}