/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:09:03 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/10 14:44:38 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_gateKeeperMode = false;
	setName("anon");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << getName() << " is born" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_gateKeeperMode = false;
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << getName() << " is born" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " is dead" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	 if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        _gateKeeperMode = rhs._gateKeeperMode;
    }
	return *this;
}

void ScavTrap::setGateKeeperMode(void)
{
	_gateKeeperMode ? _gateKeeperMode = false : _gateKeeperMode = true;
}

void ScavTrap::guardGate()
{
	setGateKeeperMode();
	if (!_gateKeeperMode)
		std::cout << "ScavTrap " << getName() << " has exit Gate Keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << getName() << " has enterred Gate Keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << 20 << " points of damage!" << std::endl;
}