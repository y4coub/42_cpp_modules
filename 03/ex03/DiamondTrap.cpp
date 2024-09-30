/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:20:59 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/30 16:48:09 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	_name = name;
	_hitpoints = FragTrap::getHitpoints();
	_energy_points = ScavTrap::getEnergyPoints();
	_attack_damage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		ScavTrap::operator=(rhs);
		FragTrap::operator=(rhs);
		_name = rhs._name;
		_hitpoints = rhs._hitpoints;
		_energy_points = rhs._energy_points;
		_attack_damage = rhs._attack_damage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << "; ClapTrap name: " << ClapTrap::getName() << std::endl;
}
