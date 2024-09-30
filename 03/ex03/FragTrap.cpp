/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:59:08 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/30 16:18:40 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	int energyPoints = getEnergyPoints();
	if (getHitpoints() > 0 && energyPoints > 0)
	{
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing "
				  << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(--energyPoints);
	}
	else
	{
		std::cout << "FragTrap " << getName() << " can't attack due to insufficient hit points or energy points!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Fragtrap " << getName() << " said HIGH FIVE GUYS!!!!" << std::endl;
}