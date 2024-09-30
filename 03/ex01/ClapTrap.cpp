/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:15:52 by yaharkat          #+#    #+#             */
/*   Updated: 2024/09/29 17:35:19 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitpoints > 0 && _energy_points > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
				  << _attack_damage << " points of damage!" << std::endl;
		_energy_points--;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " can't attack due to insufficient hit points or energy points!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitpoints -= amount;
	if (_hitpoints < 0)
		_hitpoints = 0;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining hit points: " << _hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpoints > 0 && _energy_points > 0)
	{
		_hitpoints += amount;
		_energy_points--;
		std::cout << "ClapTrap " << _name << " repairs itself, gaining "
				  << amount << " hit points! Remaining hit points: " << _hitpoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " can't repair due to insufficient hit points or energy points!" << std::endl;
	}
}

unsigned int ClapTrap::getHitpoints()
{
	return _hitpoints;
}

unsigned int ClapTrap::getEnergyPoints()
{
	return _energy_points;
}

unsigned int ClapTrap::getAttackDamage()
{
	return _attack_damage;
}

std::string ClapTrap::getName()
{
	return _name;
}

void ClapTrap::setHitpoints(unsigned int hitpoints)
{
	_hitpoints = hitpoints;
}

void ClapTrap::setEnergyPoints(unsigned int energy_points)
{
	_energy_points = energy_points;
}

void ClapTrap::setAttackDamage(unsigned int attack_damage)
{
	_attack_damage = attack_damage;
}