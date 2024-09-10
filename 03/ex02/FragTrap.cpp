/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:09:03 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/10 14:54:02 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	setName("anon");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " is born" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	setName(name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << getName() << " is born" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " is dead" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	 if (this != &rhs)
        ClapTrap::operator=(rhs);
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << getName() << " attacks " << target << " causing " << 30 << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " high fives guys!!" << std::endl;
}