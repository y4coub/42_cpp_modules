/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:26:24 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/10 14:47:58 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("anon"), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << "ClapTrap " << _name << " is born" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this == &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is dead" << std::endl;
}

void ClapTrap::attack(ClapTrap &target)
{
	if (_hitPoints < 1)
	{
		std::cout << "ClapTrap " << _name << " can't attack he is dead!" << std::endl;
		return;
	}
	if (target._hitPoints < 1)
	{
		std::cout << "ClapTrap " << target._name << " is dead!" << std::endl;
		return;
	}
	if (!_energyPoints)
	{
		std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
		return;
	}
	costEnergy(1);
	target.takeDamage(_attackDamage);
	attack(target.getName());
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << _name << " attack " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints - static_cast<int>(amount) < 0)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
	}
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " toke " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints < 1)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return;
	}
	if (!_energyPoints)
	{
		std::cout << "ClapTrap " << _name << " has no energy to be repaired!" << std::endl;
		return;
	}
	costEnergy(1);
	if (_hitPoints + amount > 10)
		_hitPoints = 10;
	else
	{
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
	}
}

std::string ClapTrap::getName() const
{
	return _name;
}

void ClapTrap::setName(std::string name)
{
	_name = name;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	_attackDamage = attackDamage;
}

void ClapTrap::costEnergy(unsigned int amount)
{
	if (_energyPoints - static_cast<int>(amount) < 0)
	{
		_energyPoints = 0;
		std::cout << "ClapTrap " << _name << " has no energy!" << std::endl;
		return;
	}
	_energyPoints -= amount;
	std::cout << "ClapTrap " << _name << " cost " << amount << " points of energy!" << std::endl;
}