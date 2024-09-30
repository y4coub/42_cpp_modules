/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:34:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/30 16:17:35 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		_gate_keeper_mode = rhs._gate_keeper_mode;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	int energyPoints = getEnergyPoints();
	if (getHitpoints() > 0 && energyPoints > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
				  << getAttackDamage() << " points of damage!" << std::endl;
		setEnergyPoints(--energyPoints);
	}
	else
	{
		std::cout << "ScavTrap " << getName() << " can't attack due to insufficient hit points or energy points!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (!_gate_keeper_mode)
	{
		std::cout << "ScavTrap is in GateKeep mode" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap is out of GateKeep mode" << std::endl;
	}
	_gate_keeper_mode = !_gate_keeper_mode;
}